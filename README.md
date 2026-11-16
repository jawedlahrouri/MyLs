# 📁 MyLs — Unix 'ls' Directory Listing Clone

[![Academic Year](https://img.shields.io/badge/Epitech-Tek1-blue?style=for-the-badge&logo=epitech&logoColor=white)](https://www.epitech.eu/)
[![Module](https://img.shields.io/badge/Module-B--PSU--100-informational?style=for-the-badge)](#)
[![Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)](#)

## 📘 Description
**MyLs** est une réimplémentation de la commande Unix `ls`. Il parcourt le système de fichiers en exploitant les primitives système POSIX (`stat`, `lstat`, `opendir`, `readdir`) et reproduit fidèlement les métadonnées et le formatage standard.

## ⚙️ Options supportées
- `-l` : Format long avec droits d'accès rwx, liens durs, propriétaire, groupe, taille, date de modification.
- `-a` : Affiche les entrées masquées commençant par un point (`.`).
- `-R` : Parcours récursif de l'arborescence des sous-dossiers.
- `-d` : Affiche les répertoires eux-mêmes plutôt que leur contenu.
- `-r` : Inverse l'ordre de tri.
- `-t` : Tri par date de dernière modification.

## 🔨 Compilation & Utilisation
```bash
make
./my_ls -laR
```
