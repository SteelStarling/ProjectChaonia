# Project Chaonia
### Created By: Taylor Hancock

A not particularly great text adventure, made for CS225 class at Embry-Riddle, possibly with more work to follow after the class ends


## A Guide to Proto-TextLang

I swear I will make a better variant later, but for now, text adventures are written as follows:

The file worldFile.txt contains the text adventure in its entirety. It is formatted (ignore indentation, used only to make this more legible):

Number of Rooms \
    Room 1 Name - Room 1 is where the Player will start \
    Room 1 Description \
    Number of Objects \
        Object 1 Name \
        Object 1 Description \
    ... \
    Number of Triggers \
        Trigger 1 Name \
        Trigger 1 Description \
    ...\
... \
Number of Flags \
    Flag 1 Name \
    Flag 1 Description \
    Flag 1 State (0 or 1)\
... \
Room N Name \
    Number of Connections in Room N \
        Char Corresponding to Connection Type 1 (f == flagged, n == normal) \
        (Flag N Name, if applicable) \
        Connection 1 Name \
        Connection 1 (Open) Description \
        (Connection 1 Closed Description) \
        (Connection 1 Error Description) \
        Connection 1 Room Name \
        Connection 1 Direction (N, NE, E, SE, S, SW, W, NW, U, D) \
    ... \
...