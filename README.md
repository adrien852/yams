# Yams (Yahtzee)
Coded in full autonomy during the summer of 2017 after my first year in computer science. I used a custom graphic library provided by my university teacher. It was a great opportunity to perfect my skills in C.
As it was my very first own software project, it is poorly structured and commented in French.

## How To Play
### Goal
Obtain the best score possible by completing the score chart.

### Rolling the dices
Each turn, you can roll up to five dice three times.

On each roll, you have to choose which dice you want to reroll by pressing their numbers on the numeric keypad. The dice still displayed are the ones you want to keep.

By pressing the "Enter" button, you confirm your choice for the next roll. If you did not choose any die, the game considers that you are satisfied with your dice and skip to the scoring.

After the third roll, the scoring automatically begins.

### Scoring
Now, you have to choose in which category you want to score with your dice combination.
You can choose only one line of the chart per dice combination. To do so, press the key displayed on its left.
Here is a sum up of the differents categories :

#### Upper section
* Aces (UN) : Score the sum of 1 in any combination
* Two (DEUX) : Score the sum of 2 in any combination
* Three (TROIS) : Score the sum of 3 in any combination
* Four (QUATRE) : Score the sum of 4 in any combination
* Five (CINQ) : Score the sum of 5 in any combination
* Six (SIX) : Score the sum of 6 in any combination

If the total of the upper section equals 63 or more, you score an extra 35 points.

#### Lower section
* Three Of A Kind (Brelan) : Score the sum of all dice if three or more dice are the same
* Four Of A Kind (Carre) : Score the sum of all dice if four or more dice are the same
* Full House (Full) : Score 25 if three dice are the same and two are the same of another number.
* Small Straight (Petite suite) : Score 30 for four sequential dice
* Large Straight (Grande suite) : Score 40 for five sequential dice
* Yahtzee (Yams) : Score 50 if all dice are the same
* Chance : Score the sum of all dice in any combination

You can choose a category even though the combination does not meet the requirements. If so, score 0.

### End of the game
When the chart is completed, the game ends and you are invited to type in your username to register your score inside a text file.
You can review it afterwards by opening `resultats.txt`
