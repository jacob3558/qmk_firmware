echo "CK MOONLANDER COMPILING............"
make clean && make moonlander:ckMoonlander

if [ -e ./.build/moonlander_ckMoonlander.bin ]; then
    cp ./.build/moonlander_ckMoonlander.bin ~/Desktop/
    open ~/Desktop
    echo "DONE! :)"
else
    echo "FAILED :("
fi

