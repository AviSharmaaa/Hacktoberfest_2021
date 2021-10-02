# Event-Reminder
> Event reminder written in python

There are 2 scripts. The cron_email.py script keeps running and checks the timetable.xlsx file for any events. It sends you a reminder email 5 mins before any weekly events

The second script timetable-maker.py can be run anytime to add a weekly event to our timetable that will henceforth have reminders scheduled

## Installation
Change directory to preferred location
```sh
git clone https://github.com/UnknownAbyss/Event-Reminder.git
cd Event-Reminder/
```
Create a virtual environment

Install requirements
```sh
pip install -r requirements.txt
```
Open the cron_email.py file in any editor of choice and input a Gmail-ID and Password in the respective variables as specified in the file. This email should allow less secure apps to access it

## Usage
Run the cron_email.py file in your terminal of choice. This file has to keep running in the background as this is the scheduler that actually sends you email reminders 5 mins before the Events

Run the timetable-maker.py file in another terminal.

Input the following information in the Window that opens:
- Name: Your name
- Email: Email address you want to be reminded on
- Event: The event title for the reminder(Class, TV show name etc)
- Day of the week: Input numbers 1-7 for Monday to Sunday
- Time: Input time of event as 24 hours time with format HH:MM. 2 am should be written as 00:20 and not 2:00
- Details: Short description of the Task

Once you press submit, it'll check if the data you entered is valid and if so, it'll schedule a weekly task for it in the timetable


## Meta
Additya Singhal
- Instagram [@addityasinghal](https://www.instagram.com/addityasinghal/) 
- addityadd@gmail.com
- [https://github.com/UnknownAbyss](https://github.com/UnknownAbyss/)
