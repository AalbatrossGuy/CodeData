import robloxpy

userID = robloxpy.User.External.GetID("AalbatrossGuy")
url = robloxpy.User.Friends.External.GetAll(userID)
print(url)
