import json
import requests
import datetime
def GetStateid(statename):
    with open('states.json') as file:
        statedict = json.load(file)
        for state in statedict['states']:
            if state['state_name'] == statename : 
                stateid = state['state_id']
    return stateid

def GetDistrictID(statename,districtname):
    disturl = f"https://cdn-api.co-vin.in/api/v2/admin/location/districts/{GetStateid(statename)}"
    req = requests.get(disturl)
    json_object = json.JSONDecoder().decode(s=req.text)
    for district in json_object['districts']:
        if district['district_name'] == districtname:
            return district['district_id']

tomorrow = datetime.datetime.today() + datetime.timedelta(days=1)
date = tomorrow.strftime("%d-%m-%Y")
dis_id = GetDistrictID(input("Enter State Name : "), input("Enter City Name: "))
url = f"https://cdn-api.co-vin.in/api/v2/appointment/sessions/public/findByDistrict?district_id={dis_id}&date={date}"
req = requests.get(url)
if req.text !=None:
  json_ob = json.JSONDecoder().decode(s=req.text)
  for session in json_ob['sessions']:
    if session['min_age_limit']==18:
        output = 'Name: '+ str(session['name']) + '\n' + 'Pincode:' + str(session['pincode']) + '\n' + 'Date:' + str(session['date'])  + '\n' + 'Available:' + '\n' + str(session['available_capacity']) + '\n' + 'Fee:' + str(session['fee']) + '\n' + 'Vaccine: ' + str(session['vaccine']) + '\n' + 'Slots:' + str(session['slots'])
        print(output)
    print("\n\n\n")    
