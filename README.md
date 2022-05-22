# APO Grafo project

Zoufal Filip <br> & <br>
Nezveda Viktor 

This project is a digital version of a famous toy "Grafo" and should add few extra functions to it.
Program can be run on mzAPO board or in Qtrvsim simulator.

# Documentation<br>
## Main menu

•	Red knob rotation: navigation in menu. <br>
•	Red knob pressed: select current option.<br>
•	Blue knob pressed: terminate program.<br><br>
User is first presented with the main menu, where he has few options: “DRAW”, “SETTINGS” and “EXIT”. He may navigate between them using red knob and selecting an option by pressing it. He also may terminate the program by pressing the blue knob. 
1.	Draw<br>
•	Red knob rotation: change x position of cursor<br>
•	Blue knob rotation: change y position of cursor<br>
•	Red knob pressed: marks current position with inverse color<br>
•	Green knob pressed: resets whole drawing pane<br>
•	Blue knob pressed: saves drawing pane and returns to main menu.<br><br>

By clicking the “DRAW” option, the user is presented with drawing interface. He can draw with cursor by rotating the red and blue knobs. Cursors color and size can be adjusted in previous settings. Information about the cursor is shown on the right side of the display in side bar. If the red knob is pressed the cursor is highlighted by inverse color. If the green knob is pressed the display is reset and if the blue knob is pressed the drawing board is saved and user returns to the main menu.

2.	Settings<br>
•	Red knob rotation: navigation in menu.<br>
•	Red knob pressed: select current option.<br>
•	Color settings<br>
o	Red knob rotation: change red factor in rgb888<br>
o	Green knob rotation: change green factor in rgb888<br>
o	Blue knob rotation: change blue factor in rgb888<br>
o	Red knob press: select current color<br>
•	Size settings<br>
o	Red knob rotation: change size<br>
o	Red knob press: select current color<br>
o	Blue knob press: enables input to console<br><br>
In settings the user can change color and size of cursor by choosing either option and then pressing red knob to select it. Afterwards he is presented with a menu, where he can change the according parameter by rotating the red knob or pressing the green knob. When changing size, the user can input data by typing it into the console and pressing enter. While selecting color, led diode should light up with the according color. Likewise, while choosing cursor size, led line should turn on relatively to the selected size.<br><br>
3.	Exit<br>
Terminates program.<br>


