# Projet CIA - Algo avancé
Projet d'algorithmie avancée du groupe CIA pour le semestre 6 de l'ISEN Méditerranée

*Réalisé par MARTINEZ Alexandre, METAIS Robin, SEIGNOUR Thomas, REPPLINGER Lucas*


## Présentation du projet
### Description 

Ce projet, que nous avons réalisé en une semaine, s'apparente à une IA symbolique. En effet, l'utilisateur doit pouvoir fournir des règles dans un fichier texte (a b -> c), puis fournir des faits (dans l'exemple, a et b). 

Le programme doit ensuite pouvoir effectuer deux méthodes, le chainage avant et le chainage arrière, de façon a répondre à ses questions : *que voulez vous demontrer* pour le chainage avant, et *prouver que XXX est vrai* pour le chainage arrière.


### Notre thème

Nous avons choisi le thème du médical, car il complète parfaitement nos exigences : nous pouvons creer des règles qui ont du sens, en suivant le principe de "symptome1 symptome2 -> maladie". 

De plus, nous pouvons rendre le programme plus intéressant en combinant les maladies, et en créant des faits au fur et a mesure (par exemple, a b -> c et c a -> d). Le fonctionnement est aussi très intuitif avec l'aspect "symptomes maladie", il est donc facile de suivre le comportement du code.

## Notice d'utilisation

Notre code comporte deux modes : 

le mode **terminal**, ainsi que le mode **Interface graphique**. Ce choix est juste un choix d'affichage, le premier étant directement sur le terminal, et le deuxième se faisant via la librairie GfxLib.

Une fois que vous avez choisi, quels sont les fonctionnalitées qui s'offrent à vous ?<br><br>


### 1 - Lire la base de données de règles

Le fichier regles.kbs est rempli de règles, il faut donc pouvoir inserer ces règles la dans les structures dédiés. **Il faut IMPERATIVEMENT que la lecture soit enclenchée avant de faire autre chose.**<br><br>


### 2 - Saisie des regles

On a la possibilitée de rajouter une règle customisée à nos besoins grâce à cette fonctionnalitée. <br><br>


### 3 - Saisie des faits

C'est ici qu'il faut saisir vos symptomes : si vous vous sentez mal, entrez ce que vous ressentez, et la magie du chainage vous dira ce que vous avez (probablement).<br><br>


### 4 et 5 - Affichage des règles et Affichage des faits

Juste des fonctions d'affichage, qui vous permet d'admirer le contenu des structures.<br><br>


### 6 - Enregistrement dans la base de règle 

Pour save les règles custom que vous avez entré, comme ça vous les aurez pour la prochaine fois.<br><br>

### 7 - Chainage avant

Pour effectuer un chainage avant, vous avez le choix : soit vous rentrez un but, et le programme vous dit si il est obtenable, soit vous ne rentrez pas de but, et le programme fonctionnera par "saturation", c'est a dire qu'il ne s'arretera pas avant l'épuisement des règles. Si vous ne souhaitez pas rentrer de but, appuyez directement sur Entrée.<br><br>

### 8 - Chainage arrière

Pour effectuer un chainage arrière, il faut forcement un but, et cela vous retournera si le but est obtenable ou non.<br><br>

### 9 - Reset bases de fait

Pour vider la base de fait, si jamais une erreur a été commise. Il suffit de la vider et de réinscrire les symptomes.<br><br>

### 10 - Quitter

Tout est dans le nom, inscrivez 10 pour quitter le programme.<br><br><br>




Il suffit donc d'inscrire le nombre correspondant à la fonctionnalitée dans le main.




