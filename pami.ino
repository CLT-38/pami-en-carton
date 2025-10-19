#include <Servo.h>

// Créer les objets servo pour les moteurs à rotation continue
Servo moteurGauche;
Servo moteurDroit;

// Définir les pins de contrôle
int pinMoteurGauche = 9;  // Pin D9 pour le moteur gauche
int pinMoteurDroit = 10;   // Pin D10 pour le moteur droit

void setup() {
  Serial.begin(9600);

  // Attacher les servos aux pins
  moteurGauche.attach(pinMoteurGauche);
  moteurDroit.attach(pinMoteurDroit);

  Serial.println("Véhicule initialisé");
  delay(500);

  // Avancer pendant 5 secondes
  Serial.println("Avance!");
  avancer();
  delay(5000);

  // Arrêter les moteurs
  Serial.println("Arrêt");
  arreter();
  delay(500);

  // Tourner à droite (45°)
  Serial.println("Rotation 45°");
  tournerDroite();
  delay(600);  // Ajuster ce délai pour obtenir environ 45° (600-700ms)

  // Arrêter
  arreter();
  delay(500);

  // Avancer pendant 2 secondes
  Serial.println("Avance!");
  avancer();
  delay(2000);

  // Arrêter les moteurs
  Serial.println("Arrêt final");
  arreter();

  Serial.println("Programme terminé");
}

void loop() {
  // Le programme ne tourne qu'une fois dans le setup()
  // Loop reste vide
}

// Fonction pour avancer
void avancer() {
  // Pour les FS90R :
  // 0° (0) = rotation complète dans un sens
  // 90° (90) = arrêt
  // 180° (180) = rotation complète dans l'autre sens

  moteurGauche.write(0);  // Moteur gauche tourne en avant
  moteurDroit.write(180);     // Moteur droit tourne en avant (inversé car monté en miroir)
}

// Fonction pour arrêter les moteurs
void arreter() {
  moteurGauche.write(90);   // Position neutre = arrêt
  moteurDroit.write(90);    // Position neutre = arrêt
}

// Fonction pour reculer (bonus)
void reculer() {
  moteurGauche.write(0);    // Moteur gauche tourne en arrière
  moteurDroit.write(180);   // Moteur droit tourne en arrière
}

// Fonction pour tourner à gauche (bonus)
void tournerGauche() {
  moteurGauche.write(0);    // Moteur gauche en arrière
  moteurDroit.write(0);     // Moteur droit en avant
}

// Fonction pour tourner à droite (bonus)
void tournerDroite() {
  moteurGauche.write(180);  // Moteur gauche en avant
  moteurDroit.write(180);   // Moteur droit en arrière
}
