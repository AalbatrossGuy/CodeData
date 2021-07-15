import discord
from discord.ext import commands
from asyncdagpi import Client, ImageFeatures
import requests

client = commands.Bot(command_prefix="^", case_insensitive=True)

dagpi = Client("MTYyMzUwMzMzMQ.876re9HvmxvFcf41LIotTu2WrHC5VNPc.edc4473be1c68f30")

@client.command()
async def wasted(ctx, member:discord.Member):
    url = member.avatar_url_as(format="png")
    base_url = f"https://some-random-api.ml/canvas/wasted?avatar={url}"
    await ctx.channel.send(base_url)

@client.command()
async def triggered(ctx, member:discord.Member = None):
    member = member or ctx.message.author
    url= member.avatar_url_as(format="png")
    img = await dagpi.image_process(ImageFeatures.triggered(), str(url))
    file = discord.File(fp=img.image, filename=f"triggered.{img.format}")
    await ctx.send(file=file)

@client.command()
async def magic(ctx, member:discord.Member = None):
    member = member or ctx.message.author
    url = member.avatar_url_as(format="png")
    img  = await dagpi.image_process(ImageFeatures.magik(), str(url))
    file = discord.File(fp=img.image, filename=f"magic.{img.format}")
    await ctx.send(file=file)

@client.command()
async def pixelate(ctx, member:discord.Member = None):
    member = member or ctx.message.author
    url = member.avatar_url_as(format="png")
    img = await dagpi.image_process(ImageFeatures.pixel(), str(url))
    file = discord.File(fp=img.image, filename=f'pixel.{img.format}')
    await ctx.send(file=file)

@client.command()
async def angel(ctx, member:discord.Member = None):
    member = member or ctx.message.author
    url = member.avatar_url_as(format="png")
    img = await dagpi.image_process(ImageFeatures.angel(), str(url))
    file = discord.File(fp=img.image, filename=f"angel.{img.format}")
    await ctx.send(file=file)

@client.command()
async def devil(ctx, member:discord.Member = None):
    member = member or ctx.message.author
    url = member.avatar_url_as(format="png")
    img = await dagpi.image_process(ImageFeatures.satan(), str(url))
    file = discord.File(fp=img.image, filename=f"devil.{img.format}")
    await ctx.send(file=file)


@client.command()
async def delete(ctx, member:discord.Member = None):
    member = member or ctx.message.author
    url = member.avatar_url_as(format="png")
    img = await dagpi.image_process(ImageFeatures.delete(), str(url))
    file = discord.File(fp=img.image, filename=f'delete.{img.format}')
    await ctx.send(file=file)

@client.command()
async def hitler(ctx, member:discord.Member = None):
    member = member or ctx.message.author
    url = member.avatar_url_as(format="png")
    img = await dagpi.image_process(ImageFeatures.hitler(), str(url))
    file = discord.File(fp=img.image, filename=f'hitler.{img.format}')
    await ctx.send(file=file)

@client.command()
async def stringify(ctx, member:discord.Member = None):
    member = member or ctx.message.author
    url = member.avatar_url_as(format="png")
    img = await dagpi.image_process(ImageFeatures.stringify(), str(url))
    file = discord.File(fp=img.image, filename = f"stringify.{img.format}")
    await ctx.send(file=file)

@client.command()
async def jail(ctx, member:discord.Member= None):
    member = member or ctx.message.author
    url = member.avatar_url_as(format="png")
    img = await dagpi.image_process(ImageFeatures.jail(), str(url))
    file= discord.File(fp=img.image, filename = f"jail.{img.format}")
    await ctx.send(file=file)


@client.event
async def on_ready():
    print('ready')

client.run("ODAzODc3OTg4NTg0MTI4NTMz.YBELtw.eEBMDTO3_kyEHRNDaUy_-IGTaQ0")
