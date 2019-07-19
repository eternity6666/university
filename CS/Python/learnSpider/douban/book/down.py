#! /bin/python3
# -*- coding: utf-8 -*-

import re
import requests
from bs4 import BeautifulSoup

def book(target_url):
    books = []
    book = requests.get(target_url)
    soup = BeautifulSoup(book.text, "lxml")
    table = soup.findAll("table", {"width": "100%"})
    for item in table:
        name = item.div.a.text.strip()
        r_name = name.replace("\n", "").replace(" ", "")
        tmp2 = item.div.span
        if tmp2:
            name2 = tmp2.text.strip().replace(":", "")
        else:
            name2 = r_name
        url = item.div.a["href"]
        info = item.find("p", {"class": "pl"}).text 
        score = item.find("span", {"class": "rating_nums"}).text.strip() 
        nums = item.find("span", {"class": "pl"}).text.strip() 
        num = re.findall("(\d+)人评价", nums)[0]  
        if item.find("span", {"class": "inq"}): 
            desc = item.find("span", {"class": "inq"}).text.strip()
        else:
            desc = "no description"
        books.append((r_name, name2, url, info, score, num, desc)) 
    return books 

if __name__ == "__main__":
    for n in range(10):
        url = "https://book.douban.com/top250?start=" + str(n * 25)
        tmp = book(url)
        with open("booktop250.cls", "a", encoding="utf-8") as d:
            for i in tmp:
                print(i[0]+", "+i[1]+", "+i[2]+", "+i[3]+", "+i[4]+", "+i[5]+", "+i[6], file=d)
