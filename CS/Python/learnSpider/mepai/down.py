#! /bin/python3
# -*- coding: utf-8 -*-

import requests
from bs4 import BeautifulSoup

all_urls = []
img_urls = []

def run(url, n):
    html = requests.get(url, headers = headers)

    soup = BeautifulSoup(html.content, "html.parser")

    for link in soup.find_all('img'):
        img_url = link.get('data-lazy-url')
        if img_url != None:
            n += 1
            print(img_url)
            response = requests.get(img_url, headers = headers)
            file_name = str(n) + '.jpg'
            with open(file_name, "wb") as f:
                f.write(response.content)
                f.close()
    return n

if __name__ == "__main__":
    headers = {
        "Referer": "https://www.mepai.me/",
        "User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.142 Safari/537.36"
    } 

    n = 0
    # all_urls.append("https://www.mepai.me/tags/日系")
    all_urls.append("https://www.mepai.me/tags/南昌大学")
    for url in all_urls:
        n = run(url, n)
    print(n)

