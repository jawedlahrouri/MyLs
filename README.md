[![Academic Year](https://img.shields.io/badge/Epitech-Tek1-blue?style=for-the-badge&logo=epitech&logoColor=white)](https://www.epitech.eu/)
[![Language: C](https://img.shields.io/badge/Language-C-00599C.svg?style=for-the-badge&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Module](https://img.shields.io/badge/Module-B--PSU--100-informational?style=for-the-badge)](#)

# 📁 MyLs — Utilitaire de Listage de Répertoire POSIX (ls clone)

**MyLs** est une réimplémentation modulaire en C de la commande standard Unix `ls`. Le programme interroge le système de fichiers pour lister les répertoires et fichiers en respectant scrupuleusement la mise en forme, les permissions et les drapeaux d'options conformes aux spécifications de GNU coreutils.

---

## 🚩 Options Supportées

| Option | Rôle & Comportement |
|---|---|
| `-l` | Format de listage détaillé (type de fichier, permissions rwx, nombre de liens matériels, propriétaire, groupe, taille en octets, date de dernière modification et nom). |
| `-a` | Affiche l'intégralité des fichiers, y compris les entrées masquées commençant par un point (`.`). |
| `-R` | Listage récursif de l'ensemble de l'arborescence des sous-répertoires. |
| `-d` | Liste les répertoires eux-mêmes comme des fichiers ordinaires, sans afficher leur contenu. |
| `-r` | Inverse l'ordre de tri des résultats. |
| `-t` | Trie les entrées selon leur date de dernière modification (les plus récentes en premier) au lieu de l'ordre alphabétique. |

---

## 🔍 Types de Fichiers Reconnus

Le mode détaillé (`-l`) distingue fidèlement les descripteurs de types POSIX via la structure `stat` :
- `-` : Fichier régulier
- `d` : Répertoire (*directory*)
- `l` : Lien symbolique (*symbolic link*)
- `c` : Périphérique en mode caractère (*character device*)
- `b` : Périphérique en mode bloc (*block device*)
- `p` : Tube nommé (*FIFO / pipe*)
- `s` : Socket réseau local

---

## 🛠️ Compilation & Utilisation

```bash
make        # Génère l'exécutable 'my_ls'
make clean  # Nettoie les fichiers objets (.o)
make fclean # Supprime les fichiers temporaires et le binaire
make re     # Recompile l'ensemble

./my_ls -laR /var/log
```
