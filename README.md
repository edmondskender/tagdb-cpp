# TagDB - Eine einfache Tag-Datenbank in C++

TagDB ist eine C++-Anwendung zur Verwaltung von Inhalten, die mit Tags versehen sind. Die Anwendung ermöglicht es, Inhalte in einer Textdatei zu speichern, nach Tags zu suchen und eine Hilfefunktion zu nutzen, die Informationen zur Verwendung bereitstellt.

## Features
- **Hilfetext anzeigen**: Zeigt den Inhalt der Datei `help.txt` an, um dem Benutzer Anweisungen zu geben.
- **Inhalt hinzufügen**: Fügt Inhalte zusammen mit Tags in die Datei `tagdb.txt` ein.
- **Suchen nach Tags**: Durchsucht `tagdb.txt` nach Inhalten, die mit bestimmten Tags versehen sind.

## Funktionsweise
### 1. Hilfefunktion
- Zeigt den Hilfetext an, der in der Datei `help.txt` gespeichert ist.
- **Verwendung**:
  ```bash
  ./tagdb --help
  ```
  oder
  
  ```bash
  ./tagdb -h
  ```
### 2. Inhalt hinzufügen
- Fügt einen neuen Inhalt in die Datei tagdb.txt ein. Tags und Inhalt werden als Argumente übergeben.
- **Verwendung**:
  ```bash
  ./tagdb -a <tags> <inhalt>
  <tags>: Eine durch Kommas getrennte Liste von Tags.
  <inhalt>: Der Inhalt, der mit den Tags verknüpft werden soll.
  ```
  Beispiel:
  ```bash
  ./tagdb -a tag1,tag2 "Mein neuer Inhalt"
  ```
### 3. Nach Tags suchen
- Durchsucht tagdb.txt und gibt Inhalte zurück, die alle angegebenen Tags enthalten.
- **Verwendung**:
  ```bash
  ./tagdb -q <tags>
  <tags>: Eine durch Kommas getrennte Liste von Tags, nach denen gesucht werden soll.
  ```
  Beispiel:
  ```bash
   ./tagdb -q tag1,tag2
  ```
