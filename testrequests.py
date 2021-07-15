import requests
def test(language, query):
    
    url = f"https://cheat.sh/{language}/{query}"
    response = requests.request("GET", url=url)
    print(response.text[:1900])


print(test('python', 'lists'))