string1 = "There is a tide in the affairs of men, Which taken at the flood, leads on to fortune. Omitted, all the voyage of their life is bound in shallows and in miseries. On such a full sea are we now afloat. And we must take the current when it serves, or lose our ventures."
string1=string1.lower()
letter_counts={}
for item in string1:
    if item not in letter_counts:
        letter_counts[item]=0
    letter_counts[item]+=1


print(letter_counts)