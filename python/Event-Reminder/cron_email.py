import smtplib, ssl, time, datetime
from openpyxl import *

'''
Replace the email and password variables with the email and password of a google account that has 
less secure apps usage enabled
'''

# Constants
email = "" #Put EMAIL here
password = "" #Put PASSWORD heres
delta = 5 #mins


def send_email(uname, subject, body, time, target_email, email=email, password=password):
	server = smtplib.SMTP_SSL("smtp.gmail.com", 465)
	server.login(email, password)
	message = "Subject: {}\n\nHey{}!\nThis is a reminder for your event: {}\nScheduled at: {}\nDetails: {}".format(subject, uname, subject, time, body)
	try:
		server.sendmail(email, target_email, message)
	except:
		print("The email you're trying to send to doesn't exist: " + target_email)
	server.quit()
	print("sent mail: " + subject)

while True:
	tt_wb = load_workbook(r"timetable.xlsx")
	sheet = tt_wb.active

	print("----")
	for row in [a for a in sheet.iter_rows()][1:]:
		print([a.value for a in row])
		if row[0].value==None:
			continue
		#test date
		today = int(row[3].value)-1 == datetime.date.today().weekday()
		
		#test time
		now = datetime.datetime.now()
		current_time = now.strftime("%H:%M")
		t_time = row[4].value
		target_time =  int(t_time[:2])*60 + int(t_time[3:]) - delta 
		current_time_num = int(current_time[:2])*60 + int(current_time[3:])
		time_diff = (current_time_num) - (target_time)
		time_diff%= 60*24

		if target_time < 0:
			today = int(row[3].value)-2 == datetime.date.today().weekday()
		
		if today and time_diff==0:
			send_email(row[0].value,row[2].value, row[5].value, row[4].value, row[1].value)


	#send_email(subject,body)
	tt_wb.close()
	time.sleep(60)