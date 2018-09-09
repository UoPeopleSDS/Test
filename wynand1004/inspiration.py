# Inspirational Sayings
# By @TokyoEdTech YouTube Channel: https://www.youtube.com/channel/UC2vm-0XX5RkWCXWwtBZGOXg

# First test of UoPeopleSDS Organizational Repository
# Just trying to understand how GIT works
# Thanks to Sage for getting the ball rolling!

import tkinter
import random

root = tkinter.Tk()
root.title("Inspiration")
root.geometry("225x75")

lbl_inspiration = tkinter.Label(root, wraplength=200)
lbl_inspiration.pack()

sayings = [
    "All things are difficult before they are easy. - John Norley",
    "Don't wait. The time will never be just right. - Napoleon Hill",
    "Wherever you go, go with all your heart. - Confucius",
    "Eighty percent of success is showing up. - Woody Allen",
    "A jug fills drop by drop. - Buddha"
]

def new_inspiration():
    saying = random.choice(sayings)
    lbl_inspiration["text"] = saying
    root.after(10000, new_inspiration)
    
new_inspiration()

root.mainloop()
