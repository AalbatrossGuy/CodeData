text = input()
text = text.replace('`', '') if '`' in text else text
print(text)
