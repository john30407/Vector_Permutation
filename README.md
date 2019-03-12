# Vector_Permutation
Some random code I spun up for an attempt at a Monte-Carlo Process.

Data simulation is based on the bid evaluation process but not cloned

This is a representation between 4 competiters: A, B, C, D

Couple Steps involved

#1 Iterated through all possible permutation of a V_LEN size vector, each with C_LEN possible inputs
    - example of V_LEN = 3, C_LEN = 2: vector[V_LEN] = {{1,2},{1,2},{1,2}}
   
   Applied each permutation to the formula. Output represent the score of one criteria with that specific set of vectors
   
#2 Each scoring represents 1 criteria, with a total of 4 criteria each with its own weight. 
   Final number of permutation for V_LEN = 6, C_LEN =5, and 4 criteria would be (5^6)^4 = 5.96 x 10^16
   Realizing the number is too big, we understand the value of Monte Carlos in this situation.
   Randomly generate 1/10 of the number of permutation to represent the possible data as a whole
   
#3 Switch gears: attempting to streamline calculation for final scoring
   Web IDE that I was using to develop Score Calculation doesn't have a console to take user values
   Used hardcoded values defined at top, can adjust 
   
