
    Juego juego;
    juego.setMapa(tablero);
    juego.ejercito1 = ejercito1; juego.n1 = n1;
    juego.ejercito2 = ejercito2; juego.n2 = n2;
    juego.mostrarMapa();


    // int xAux = ejercito2[6] -> getPos().getX();
    // int yAux = ejercito2[6] -> getPos().getY();

    ejercito2[6] -> posPrevia = ejercito2[6] -> getPos();
    
    cout << ejercito2[6] -> posPrevia.getX() << ejercito2[6] -> posPrevia.getY() << endl;
    ejercito2[6] -> moverse();
    cout << ejercito2[6] -> posPrevia.getX() << ejercito2[6] -> posPrevia.getY() << endl;
    cout << ejercito2[6] -> getPos().getX() << ejercito2[6] -> getPos().getY() << endl;

    if (ejercito2[6] -> combatePendiente == 1){ // Esto puede ser parte de loop principal
        juego.combate(ejercito2[6], juego.llamarEnemigo(ejercito2[6] -> getPos(), ejercito1, n1));
    }
    //     Personaje *enemigo = juego.llamarEnemigo(ejercito2[6] -> getPos(), ejercito1, n1);
    //     juego.combate(ejercito2[6], enemigo);

    //     ejercito2[6] -> pos.set(xAux, yAux);
    //     tablero -> eliminarPersonaje(ejercito2[6]);
        
    //     if (enemigo -> estado == "muerto"){
    //         ejercito2[6] -> pos.set(enemigo -> pos.getX(), enemigo -> pos.getY());
    //         tablero -> eliminarPersonaje(enemigo);
    //         tablero -> agregarPersonaje(ejercito2[6]);
    //     }
    // }

    // if (ejercito1[3] -> getPos().getX() == ejercito2[4] -> getPos().getX() && ejercito1[3] -> getPos().getY() == ejercito2[4] -> getPos().getY())

    juego.mostrarMapa();

    // tablero -> eliminarPersonaje(ejercito1[0]);

    for (int i = 0; i < n1; i++) delete ejercito1[i];
    delete[] ejercito1;

    for (int i = 0; i < n2; i++) delete ejercito2[i];
    delete[] ejercito2;

    soldados.close();
    return 0;
}