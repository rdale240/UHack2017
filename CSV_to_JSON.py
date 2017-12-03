'''
Created on Dec 2, 2017

@author: Richard
'''
import pandas as pd
import json
import csv
import sys

infile = open('conglomeration.csv', 'r', encoding = 'utf-8', errors = "ignore")
df = pd.read_csv(infile, ';')
js = df.to_json(None, 'records')

#fieldnames = ("username";"date";"retweets";"favorites";"text";"geo";"mentions";"hashtags";"id";"permalink")
#reader = csv.DictReader(infile, fieldnames)

#out = json.dumps([row for row in reader])
#data = []
#with open('conglomeration.csv') as infile:
#    for row in csv.DictReader(infile):
#        data.append(row)
        
#json_data = json.dumps(data,sort_keys = True)
output_file = open ('conglomeration.json', 'w')
#with open(output_file, "w", encoding="utf-8") as out:
output_file.write(js)
