# Bistromathique
Projet fin de piscine 1ère année Epitech

Une bistromathique est une calculette gérant des nombres sans limite de taille, 
avec n'importe quelle base et n'importe quels opérateurs (dans l'ordre de l'exemple).
Le calcul est pris en entrée standard.

Projet mis à la norme d'Epitech, passant 100% des tests.
<br>Il est cependant imparfait : malloc non free et convert_base lourd.

Compilation par Makefile. (make all)

#

Usage:
<br>./calc -h
<br>./calc base operators lenght

Exemple:
<br>echo "3+3" | ./calc "0123456789" "()+-\*/%" 3
<br>echo "bab" | ./calc "012b456789" "()a-\*/%" 3
  
#

Projet mis à titre d'exemple pour vous aider a vous inspirer.
<br>Copier le projet tel quel est inutile pour progresser.

<br>Développé par Victorien Fischer, Yann Probst et Thibaut Cornolti.
