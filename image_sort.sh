#!/bin/bash

chemin_dossier_image="$1"

est_lisible() {
    feh -U "$1"
    return "$?"
}

# Utilisation de la commande find pour parcourir les images dans le dossier et les sous-dossiers
while IFS= read -r -d '' image; do
    if est_lisible "$image"; then
        echo "$image lisible"
    else
        echo "$image illisible"
        rm "$image"
        echo "Image supprimée."
    fi
done < <(find "$chemin_dossier_image" -type f -iname "*.jpg" -print0)

