import requests

url = "http://apimeme.com/meme?meme=10-Guy&top=Top+text&bottom=Bottom+text"

data = requests.request("GET", url=url).json()
print(data)
