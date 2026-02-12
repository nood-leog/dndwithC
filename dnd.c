#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define RACE_LIST(X) \
    X(HUMAN,       "Human")      \
    X(ELF,         "Elf")        \
    X(DWARF,       "Dwarf")      \
    X(HALFLING,    "Halfling")   \
    X(ORC,         "Orc")        \
    X(GNOME,       "Gnome")      \
    X(DRAGONBORN,  "Dragonborn") \
    X(TIEFLING,    "Tiefling")   \
    X(HALF_ELF,    "Half-Elf")   \
    X(HALF_ORC,    "Half-Orc")

#define CLASS_LIST(X) \
    X(BARBARIAN,   "Barbarian") \
    X(BARD,        "Bard")      \
    X(CLERIC,      "Cleric")    \
    X(DRUID,       "Druid")     \
    X(FIGHTER,     "Fighter")   \
    X(MONK,        "Monk")      \
    X(PALADIN,     "Paladin")   \
    X(RANGER,      "Ranger")    \
    X(ROGUE,       "Rogue")     \
    X(SORCERER,    "Sorcerer")  \
    X(WARLOCK,     "Warlock")   \
    X(WIZARD,      "Wizard")

#define ALIGNMENT_LIST(X) \
    X(LAWFUL_GOOD,     "Lawful Good")    \
    X(NEUTRAL_GOOD,    "Neutral Good")   \
    X(CHAOTIC_GOOD,    "Chaotic Good")   \
    X(LAWFUL_NEUTRAL,  "Lawful Neutral") \
    X(TRUE_NEUTRAL,    "True Neutral")   \
    X(CHAOTIC_NEUTRAL, "Chaotic Neutral")\
    X(LAWFUL_EVIL,     "Lawful Evil")    \
    X(NEUTRAL_EVIL,    "Neutral Evil")   \
    X(CHAOTIC_EVIL,    "Chaotic Evil")

//enum gen
enum Race {
#define X(a, b) a,
    RACE_LIST(X)
#undef X
};

enum Class {
#define X(a, b) a,
    CLASS_LIST(X)
#undef X
};

enum Alignment {
#define X(a, b) a,
    ALIGNMENT_LIST(X)
#undef X
};

//string array gen
const char* RaceStrings[] = {
#define X(a, b) b,
    RACE_LIST(X)
#undef X
};

const char* ClassStrings[] = {
#define X(a, b) b,
    CLASS_LIST(X)
#undef X
};

const char* AlignmentStrings[] = {
#define X(a, b) b,
    ALIGNMENT_LIST(X)
#undef X
};

struct Sheet
{
  //Strength, Dexterity, Constitution, Intelligence, Wisdom
  int strength, dexterity, constitution, intelligence, wisdom;

  //player name : string
  char playerName[50];

  //character name : string
  char characterName[50];

  //race : enum
  enum Race race;

  //class : enum
  enum Class class; 

  //alignment : enum 
  enum Alignment alignment; 
};

//function prototypes
int diceroll(int range);
void sheetprinter(struct Sheet character);
void nameInput(struct Sheet *character);
int select_option(const char* name, const char* options[], int count);

int main()
{
  srand(time(NULL));

  //create an instance of the sheet struct 
  struct Sheet character;

  nameInput(&character);

  int raceCount = sizeof(RaceStrings) / sizeof(RaceStrings[0]);
  character.race = select_option("Race", RaceStrings, raceCount);

  int classCount = sizeof(ClassStrings) / sizeof(ClassStrings[0]);
  character.class = select_option("Class", ClassStrings, classCount);

  int alignmentCount = sizeof(AlignmentStrings) / sizeof(AlignmentStrings[0]);
  character.alignment = select_option("Alignment", AlignmentStrings, alignmentCount);
  
  character.strength = diceroll(20);
  character.dexterity = diceroll(20);
  character.constitution = diceroll(20);
  character.intelligence = diceroll(20);
  character.wisdom = diceroll(20);

  sheetprinter(character);
  

  return 0;
}

int diceroll(int range)
{

  int roll = (rand() % range) + 1;
  
  return roll;
}

void nameInput(struct Sheet *character)
{
  printf("Enter player name: \n");
  scanf(" %[^\n]s", character->playerName);

  printf("Enter character name: \n");
  scanf(" %[^\n]s", character->characterName);
}


int select_option(const char* name, const char* options[], int count) 
{
    int choice = -1;

    printf("\nChoose a %s:\n", name);
    for (int i = 0; i < count; i++) {
        printf("[%d] %s\n", i + 1, options[i]);
    }

    while (choice < 1 || choice > count) {
        printf("Enter (1-%d): ", count);
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // clear buffer
            continue;
        }
    }

    return choice - 1;
}

void sheetprinter(struct Sheet character)
{
  printf("\n============================\n");
  printf("Player Name: %s\n", character.playerName);
  printf("Character Name:   %s\n", character.characterName);

  printf("Race:   %s\n", RaceStrings[character.race]);
  printf("Class:  %s\n", ClassStrings[character.class]);
  printf("Alignment:  %s\n", AlignmentStrings[character.alignment]);


  printf("\n");

  printf("--- Character Stats ---\n");
  printf("STR: %i\n", character.strength);
  printf("DEX: %i\n", character.dexterity);
  printf("CON: %i\n", character.constitution);
  printf("INT: %i\n", character.intelligence);
  printf("WIS: %i\n", character.wisdom);

}

//this program is to simulate a dice roll for character stats for a game like d&d