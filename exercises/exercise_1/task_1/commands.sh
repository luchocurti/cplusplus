
# 1. Count how many lines are there in "data.dat".
echo "1. data.dat has" && wc -l data.dat && echo "lines" && echo " "

# 2. Count how many lines of those contain "dolor" or "dalor"?
echo "2. " && grep -E "dalor|dolor" data.dat | wc -l && echo "lines contain \"dolor\" or \"dalor\"" && echo " "

# 3. Count how many words are there in "data.dat"?
echo "3. data.dat has" && wc -w data.dat && echo "words" && echo " "

# 4. Count how many of those start with "mol"?
echo "4. data data has" && grep -i ' mol' data.dat -c && echo "words that start with \"mol\"" && echo " "
