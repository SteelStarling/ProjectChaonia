# Project Chaonia
### Created By: Taylor Hancock

A not particularly great text adventure, made for CS225 class at Embry-Riddle, possibly with more work to follow after the class ends


## A Guide to Proto-TextLang

I swear I will make a better variant later, but for now, text adventures are written as follows:

The file worldFile.txt contains the text adventure in its entirety. It is formatted (ignore indentation, used only to make this more legible):

Number of Flags \
&emsp;Flag 1 Name \
&emsp;Flag 1 State (0 or 1)\
... \
Number of Rooms \
&emsp;Room 1 Name - Room 1 is where the Player will start \
&emsp;Room 1 Description \
&emsp;Number of Objects \
&emsp;&emsp;Object 1 Name \
&emsp;&emsp;Object 1 Description \
&emsp;... \
&emsp;Number of Triggers \
&emsp;&emsp;Trigger 1 Name \
&emsp;&emsp;Trigger 1 On Description \
&emsp;&emsp;Trigger 1 Off Description \
&emsp;&emsp;Trigger 1 Flag \
&emsp;...\
... \
Room N Name \
&emsp;Number of Connections in Room N \
&emsp;&emsp;Char Corresponding to Connection Type 1 (f == flagged, n == normal) \
&emsp;&emsp;Connection 1 Name \
&emsp;&emsp;Connection 1 (Open) Description \
&emsp;&emsp;(Connection 1 Closed Description) \
&emsp;&emsp;(Connection 1 Error Description) \
&emsp;&emsp;(Flag N Name, if applicable) \
&emsp;&emsp;Connection 1 Room Name \
&emsp;&emsp;Connection 1 Direction (N, NE, E, SE, S, SW, W, NW, U, D) \
&emsp;... \
...