//Script by vit0rr - https://github.com/vit0rr
//Your Token
let authToken = 'YourToken'; //input your token here

//ID of user that you want remove messages in DM
var idUser = ['ID']; //input id user here

//Optional option => last message send
if (typeof (beforeId) === 'undefined') {
	var beforeId = null;
}
//Start Script
clearMessages = function () {
	//Connection with Discord
	const channel = window.location.href.split('/').pop();
	const baseURL = `https://discordapp.com/api/channels/${channel}/messages`;
	const headers = { Authorization: authToken };

	let clock = 0;
	let interval = 1300;
	let messagesStore = [];

	//Delay
	function delay(duration) {
		return new Promise((resolve) => {
			setTimeout(resolve, duration);
		});
	}

	//Load Messages
	function loadMessages() {
		let url = `${baseURL}?limit=100`;
		if (beforeId) {
			url += `&before=${beforeId}`;
		}
		return fetch(url, { headers });
	}

	//Delete Message
	function tryDeleteMessage(message) {
		if (idUser.indexOf(message.author.id) === -1 && message.content != null) {
			console.log(`Message by ${message.author.username} (${message.content.substring(0, 30)}...) deleted.`);
			return fetch(`${baseURL}/${message.id}`, { headers, method: 'DELETE' });
		}
	}

	//Filter messages by ID
	function filterMessages(message) {
		return idUser.indexOf(message.author.id) === -1;
	}

	function onlyNotDeleted(message) {
		return message.deleted === false;
	}

	loadMessages()
		.then(resp => resp.json())
		.then(messages => {
			if (messages === null || messages.length === 0) {
				console.log(`all messages have been deleted!`);
				console.log(`Restart de page!`);
				return;
			}
			beforeId = messages[messages.length - 1].id;
			messages.forEach(message => { message.deleted = false; });
			messagesStore = messagesStore.concat(messages.filter(filterMessages));
			return Promise.all(messagesStore.filter(onlyNotDeleted).map(async (message) => {
				await delay(clock += interval);
				const resp = await tryDeleteMessage(message);
				if (resp && resp.status === 204) {
					message.deleted = true;
					return resp.text();
				}
				const result = undefined;
				if (result) {
					result = JSON.parse(result);
					if (result.code === 50003) {
						console.log(`Sorry, my system can't remove message by: ${message.author.username}, skipping`);
						idUser.push(message.author.id);
						messagesStore = messagesStore.filter(filterMessages);
					}
				}
			}));
		})
		.then(function () {
			if (messagesStore.length !== 0 && messagesStore.length < 100) {
				clearMessages();
			} else {
				ClearLoop();
			}
		});
};
//loop script
function ClearLoop() {
	clearMessages();
}
//ClearLoop
ClearLoop();

console.clear()