from pytube import YouTube
#from sys import argv

link = 'https://www.youtube.com/watch?v=087UC0i4_Xc'
yt = YouTube(link)
yd = yt.streams.get_highest_resolution()
yd.download('/Users/james/Videos')