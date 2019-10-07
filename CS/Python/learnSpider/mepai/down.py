#! /bin/python3
# -*- coding: utf-8 -*-

import requests
from bs4 import BeautifulSoup

# 储存页面的url
all_urls = []
# 储存图片的url
img_urls = []

# 储存路径
## linux的路径
# path = "/home/eternity6666/Pictures/" 
## Windows的路径
path = "E:\摄影\mepai\\"

# 爬取地址为url的图片, 并储存到本地, 将图片命名为n.jpg
def run(url, n):
    # 使用requests的get()方法获取页面信息
    html = requests.get(url, headers = headers)

    # 对requests.get()返回的页面信息进行解析
    soup = BeautifulSoup(html.content, "html.parser")

    # 访问页面中所有的图片
    for link in soup.find_all('img'):
        # 由分析页面可知, 图片的地址位于img的data-lazy-url属性中
        img_url = link.get('data-lazy-url')
        # 判断是否获取成功
        if img_url != None:
            # 爬取数+1
            n += 1
            # 由于mepai.com的自身的设置, 默认清晰度为720w, 此处是为了提高爬取到的图片的清晰度
            tmp_url = ''
            for c in img_url:
                if c == '!':
                    break
                else:
                    tmp_url = tmp_url + c
            img_url = tmp_url + '!1920w.jpg'
            # 打印图片的url地址
            print(img_url)
            # 使用requests的get()方法获取图片信息
            response = requests.get(img_url, headers = headers)
            # 文件的储存路径
            file_name = path + str(n) + '.jpg'
            with open(file_name, "wb") as f:
                f.write(response.content)
                f.close()
    return n

# 程序的入口
if __name__ == "__main__":
    # 定义headers信息, 模拟浏览器
    headers = {
        "Referer": "https://www.mepai.me/",
        "User-Agent": "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/76.0.3809.100 Safari/537.36"
        # "User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.142 Safari/537.36"
    } 

    n = 0

    # 添加页面url
    # all_urls.append("https://www.mepai.me/tags/日系")
    all_urls.append("https://www.mepai.me/tags/南昌大学")
    url = "https://www.mepai.me/recommend?page="
    for i in range(10):
        all_urls.append(url + str(i))
    
    # 爬取页面中的图片
    for url in all_urls:
        n = run(url, n)

    # 打印成功爬取了多少图片
    print(n)
