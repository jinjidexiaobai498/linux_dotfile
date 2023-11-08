#!/bin/bash

REPO="https://github.com/aaron-williamson/base16-alacritty.git"
DEST="$HOME/.config/alacritty/store-themes/aarors-williamson-colorschemes"
# Get colorschemes
git clone $REPO $DEST
# Create symlink at default colors location (optional)
ln -s "$DEST/colors" "$HOME/.config/alacritty/colors"

REPO=https://github.com/eendroroy/alacritty-theme.git
DEST="$HOME/.config/alacritty/store-themes/eendroroy-colorschemes"
# Get colorschemes
git clone $REPO $DEST
# Create symlink at default colors location (optional)
ln -s "$DEST/themes" "$HOME/.config/alacritty/colors"

