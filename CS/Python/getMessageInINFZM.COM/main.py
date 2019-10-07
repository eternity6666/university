# -*- coding: utf-8 -*-

import requests
import re  # 调用正则匹配功能
from bs4 import BeautifulSoup

homeUrl = "http://www.infzm.com"  # 待爬取网站网址
header = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/76.0.3809.132 Safari/537.36"
} # 定义headers信息, 模拟浏览器
path = "E:\\"
filePath = path + 'a.csv'
idContent = 0

allContents = set()  # 储存南方周末所有文章链接
allTopics = set()  # 储存南方周末各类导航栏目

def reMatch(pattern, url):
    if re.match(pattern, url) != None:
        return True


def download(url):
    url = homeUrl + url
    html = requests.get(url, headers = header)
    soup = BeautifulSoup(html.content, 'html.parser')
    print(soup.find('h1'))
    

def findAllContext(url):
    html = requests.get(url, headers=header)
    soup = BeautifulSoup(html.content, "html.parser")
    aLink = soup.find_all('a')
    for link in aLink:
        a_url = link.get('href')
        if a_url == None:
            break

        if reMatch('/topics/', a_url):
            allTopics.add(a_url)
        elif reMatch('/contents/', a_url):
            if a_url not in allContents:
                download(a_url)
            allContents.add(a_url)


if __name__ == "__main__":

    idContent = 0
    findAllContext(homeUrl)
    