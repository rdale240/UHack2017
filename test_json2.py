import json
import datetime
import random
from decimal import Decimal

data = {}

#use 1200 days later
for x in range (1200):
    today = datetime.datetime.now()
    yesterday = today - datetime.timedelta(days=x)
    date = yesterday.strftime("%Y-%m-%d")
    pos_val = (random.random())
    neg_val = (random.random()) * -1
    avg_val = (neg_val + pos_val)/2
    avg = round(Decimal(avg_val), 3)

    # print("date: " + date)
    # print("pos: " + str(pos_val))
    # print("neg: " + str(neg_val))
    # print("avg: " + str(avg_val))
    
    data[date] = str(avg)

with open('dates.json', 'w+') as outfile:
    json.dump(data, outfile)


# print (str(json_data))
