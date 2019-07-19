#! /bin/python3
# -*- coding: utf-8 -*-

import requests
from lxml import etree
import urllib

def run(start):
    url = 'https://movie.douban.com/top250?start=' + str(start) + '&filter='
    data = requests.get(url)
    html = etree.HTML(data.text)
    res = html.xpath('//img/@src')
    for i in range(len(res)):
        urllib.request.urlretrieve(res[i], filename = "./movie/" + str(start+i) + ".jpg")
        print(str(start+i)+".jpg")

if __name__ == '__main__':
    for i in range(10):
        run(start = i * 25)

