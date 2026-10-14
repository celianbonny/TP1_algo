#include "questions.h"

char* ALLQUESTIONS[20][6] = {
  {"Quelle est la capitale de l'Italie ?", "Madrid", "Rome", "Athènes", "Lisbonne", "B"},
  {"Qui a peint la Joconde ?", "Léonard de Vinci", "Michel-Ange", "Raphaël", "Donatello", "A"},
  {"Quel est le symbole chimique de l'or ?", "Ag", "Au", "Fe", "Pt", "B"},
  {"En quelle année a eu lieu la chute du mur de Berlin ?", "1987", "1989", "1991", "1993", "B"},
  {"Qui a écrit 'Les Misérables' ?", "Victor Hugo", "Émile Zola", "Molière", "Balzac", "A"},
  {"Quel est le plus grand océan du monde ?", "Atlantique", "Pacifique", "Arctique", "Indien", "B"},
  {"Combien y a-t-il de planètes dans le système solaire ?", "7", "8", "9", "10", "B"},
  {"Quelle est la monnaie officielle du Japon ?", "Yuan", "Yen", "Won", "Ringgit", "B"},
  {"Qui a découvert la pénicilline ?", "Louis Pasteur", "Alexander Fleming", "Marie Curie", "Joseph Lister", "B"},
  {"Quel est le plus long fleuve du monde ?", "Nil", "Amazon", "Yangtsé", "Mississippi", "B"},
  {"Quelle est la langue la plus parlée dans le monde ?", "Anglais", "Espagnol", "Mandarin", "Hindi", "C"},
  {"Qui est l'auteur de '1984' ?", "George Orwell", "Aldous Huxley", "Jules Verne", "Isaac Asimov", "A"},
  {"Quel pays a gagné la Coupe du monde de football 2018 ?", "Brésil", "France", "Allemagne", "Argentine", "B"},
  {"Quelle planète est surnommée la planète rouge ?", "Vénus", "Mars", "Jupiter", "Mercure", "B"},
  {"Quel est le nombre de côtés d'un hexagone ?", "5", "6", "7", "8", "B"},
  {"Qui a formulé la théorie de la relativité ?", "Newton", "Einstein", "Galilée", "Copernic", "B"},
  {"Quel est le plus grand désert du monde ?", "Sahara", "Gobi", "Kalahari", "Antarctique", "D"},
  {"Quel métal est liquide à température ambiante ?", "Fer", "Mercure", "Plomb", "Aluminium", "B"},
  {"Quelle est la capitale du Canada ?", "Toronto", "Montréal", "Ottawa", "Vancouver", "C"},
  {"Combien de cordes a un violon ?", "4", "5", "6", "7", "A"}
};

int* AJOUTTAB(int* tab, int actualSize, int x) {
	int* r = realloc(tab, (1 + actualSize) * sizeof(int));
	r[actualSize] = x;
	return r;
}

int* LSQUESTIONS() {
	int* r = malloc(20 * sizeof(int));
	for (int i = 0; i < 20; i++) { r[i] = i; }
	return r;
}

char** UNEQUESTION(int k) {
	return ALLQUESTIONS[k];
}
