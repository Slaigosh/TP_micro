# TP_micro
# 1 Saisie du schéma
## 1.2 Le microcontrolleur sous KiCad
### Q13
PB9 est relié à la masse car c'est le pin boot0. 
Si le pin boot0 est relié à la masse, on boot dans la usermemory (notre code).
Si le pin boot0 est relié à Vdd, on boot dans la systemmemory (le bootloader).
Donc on veut boot dans notre code.

### Q14
L1, C5, C7 sont des composant de filtrage d'allimentation (données dans la datasheet).

## 1.3 Le reste du schéma
### Q3
Les données sont dans la page 3 de la datasheet, dans Recommended Operating Conditions.

### Q5
Les données sont dans la page 6 de la datasheet, dans AC Characteristics.

### Q6
La broche CS sert d'enable dans la communication SPI.

### Q7
C'est le pin de synchronisation du DAC.

### Q8
Il n'y a pas de MISO parce que le DAC ne communique pas au master

### Q10
C'est dans la datasheet du STLINKV3, page 19.

## 1.4 Affectation des empreintes
### Q3
0805, 009 et 1206 sont des tailles d'empreintes pour des composants passifs.
Par exemple, 0805 veut dire 8mm de longueur sur 5mm de largeur.

### Q4
LQFP, SOT-223 et SOIC sont des formes de boiter avec leur empreinte qui correspond.

# 2 Routage du circuit

# 3 Ecriture du firmware

## 3.1 Affectation des empreintes
### Q4
__STATIC_INLINE se met avant une fonction pour indiquer au compilateur de remplacer les appels de la fonction par le contenu de la fonction ( c'est comme une focntion macro).

### Q5
Si c'est une fonction INLINE dans un Header, elle est copié dans la source.

## 3.2 LED simple
### Q2
On a prit 64 car "16MHz/64=250KHz". Du coup avec une période de 255 pour le compteur du timer, on obtient environ 1KHz de période de PWR.

## 3.3 LED simple
### Q3
Pour PSC on met 64 et pour ARR 250, ce qui nous ramène à 1KHz.

### Q6
La routine d'ISR se situe dans "stm32l0xx_it.c"

### Q7
Il manque la désactivation du flag d'interruption.

### Q8
Ca va lancer l'interruption en boucle.

### Q9
Dans la routine d'interrution, il faut écrire le flag.

## 3.4 UART, un simple echo
### Q5
Il faut rajouter un & dans la ligne SerialTransmit(&ch,1);
Car il faut passer un pointeur sur le char.

