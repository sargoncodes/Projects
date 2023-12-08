import tkinter as tk

window = tk.Tk()

window.geometry("1000x1000")

window.title("Sargon's Tkinter")

# Packed items
label = tk.Label(window, text="Yo!", font=('Arial', 24))
label.pack(padx=0, pady=20)

textbox = tk.Text(window, height=2, font=('Arial', 18))
textbox.pack(padx=10, pady=10)

entry = tk.Entry(window, text="does this work?", font=('Arial', 18))
entry.pack(padx=10, pady=0)

button = tk.Button(window, text="I'm a button!", font=('Arial', 18))
button.pack(padx=10, pady=20)

# Grided items
framework = tk.Frame(window) # Grided items must be gridded into a framework (Frame())
framework.columnconfigure(0, weight=1) # Each column in the framework needs to be pre-configured
framework.columnconfigure(1, weight=1)
framework.columnconfigure(2, weight=1)

item1 = tk.Button(framework, text="item1", font=('Arial', 18))
item1.grid(row=0, column=0, sticky= tk.W + tk.E) # tk.W sticks items to the west side of the grid framework, tk.E to the east side

item2 = tk.Button(framework, text="item2", font=('Arial', 18))
item2.grid(row=0, column=1, sticky= tk.W + tk.E)

item3 = tk.Button(framework, text="item3", font=('Arial', 18))
item3.grid(row=0, column=2, sticky= tk.W + tk.E)

item4 = tk.Button(framework, text="item4", font=('Arial', 18))
item4.grid(row=1, column=1, sticky= tk.W + tk.E)

framework.pack(fill='x', pady=30) # Has to be packed because of prior pack usage | fill='x' is used to stretch grid framework in the x direction

# Placed items
wacky_item = tk.Button(window, text="I'm\nQuircky", font=('Arial', 18)) # Items can be placed randomly
wacky_item.place(x=250, y=750, height=100, width=100)

window.mainloop()