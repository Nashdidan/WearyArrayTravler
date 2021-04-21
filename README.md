# WearyArrayTravler

User input may comes in 3 formats: CSV, TSV, JSON find examples on dir 'Resources'.

The first index is 0, that’s where the algorithm starts.

Algorithm may only ‘jump’ forward or backwards in the array according to the
value in the ‘current’ element (e.g. if the value at index 0 is 3 the algo may only
advance to index 3. if the value at index 3 is 2 – the algo may advance to both
index 5 and index 1).

Examples:
[4, 4, 1, 1, 2, 2, 1000, 1] will return TRUE, since there is a route from the first element
to the last element which goes: 0 (4) → 4 (2) → 2 (1) → 1 (4) → 5 (2) → 7] .
[4, 2, 1, 3, 2, 2, 1000, 1] will return FALSE, since there is no route from the first
element to the last element.

 _   _           _    ______ _     _             
| \ | |         | |   |  _  (_)   | |            
|  \| | __ _ ___| |__ | | | |_  __| | __ _ _ __  
| . ` |/ _` / __| '_ \| | | | |/ _` |/ _` | '_ \ 
| |\  | (_| \__ \ | | | |/ /| | (_| | (_| | | | |
\_| \_/\__,_|___/_| |_|___/ |_|\__,_|\__,_|_| |_|
                                                 
                                                 
