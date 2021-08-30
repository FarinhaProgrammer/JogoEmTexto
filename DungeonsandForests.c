#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void ambiente(int amb, int *cansado, char personagem[]){
        printf("Escolha uma opcao:\n");
        switch (amb){
        
      case 1:
        printf("0 - Sair do jogo\n");
        printf("1 - Ir para floresta\n");
        printf("2 - Ir para dungeon\n");
        printf("3 - Ver inventario\n");
        printf("4 - Criar itens\n");
        break;
        
      case 2:
        if (*cansado > 0){
            printf("0 - Sair do jogo\n");
            printf("1 - Voltar para casa\n");
            printf("2 - Andar pela floresta\n");
            printf("3 - Vasculhar os arbustos\n");
            printf("4 - Ver inventario\n");
            printf("5 - Criar itens\n");
        }else{
            printf("%s se cansou\n", personagem);
            printf("1 - Voltar para casa\n");
        }
        break;
    
      case 3:
        if (*cansado > 0){
            printf("0 - Sair do jogo\n");
            printf("1 - Voltar para casa\n");
            printf("2 - Explorar a masmorra\n");
            printf("3 - Vasculhar os esqueletos\n");
            printf("4 - Ver inventario\n");
            printf("5 - Criar itens\n");
        }else{
            printf("%s se cansou\n", personagem);
            printf("1 - Voltar para casa\n");
        }
        break;
    }
    return;
}

int ondeesta(int amb, int *cansado){
  printf("Voce esta ");
  switch (amb){

    case 1:
        printf("em casa\n");
        return 4;
        break;
    case 2:
        printf("na floresta\n");
        if (*cansado > 0){
            return 5;
        }else{
            return 1;
        }
        break;
    case 3:
        printf("na dungeon\n");
        if (*cansado > 0){
            return 5;
        }else{
            return 1;
        }
        break;
    }
return 0;
}

void craft(int *atk, int *herb, int *hpotion, int *mhpotion, int *ossos, int *confesp, int *confarc, char personagem[]){
    int esc, qtd, c;
    printf("Escolha um item para criar:\n");
    printf("1 - Pocao de Cura\n");
    printf("2 - Mega pocao de Cura\n");
    printf("3 - Espada da Masmorra\n");
    printf("4 - Arco da Floresta\n");
    printf("Sua escolha: ");
    scanf("%d", &esc);
    switch (esc){

        case 1:
            printf("Pocao de Cura:\n");
            printf("Preco: 3 ervas\n");
            printf("Para cancelar o craft digite 0\n");
            printf("Quantidade: ");
            scanf("%d", &qtd);
            if (qtd == 0){
                printf("Cancelando craft...\n");
            }else if (qtd < 0){
                while (1){
                    printf("Numero invalido!\n");
                    printf("Redigite, por favor: ");
                    scanf("%d", &qtd);
                    if (qtd == 0){
                        printf("Cancelando craft...\n");
                        break;
                    }else if(qtd > 0){
                        break;
                    }
                }
            }
            if (qtd > 0){
                if (qtd * 3 > *herb){
                    printf("A quantidade de ervas eh insuficiente\n");
                }else{
                    for (c = 0; c < qtd; c++){
                        *hpotion += 1;
                    }
                    printf("%s criou %d pocoes", personagem, qtd);
                }
            }
        break;

        case 2:
            printf("Mega pocao de Cura:\n");
            printf("Preco: 10 ervas\n");
            printf("Para cancelar o craft digite 0\n");
            printf("Quantidade: ");
            scanf("%d", &qtd);
            if (qtd == 0){
                printf("Cancelando craft...\n");
            }else if (qtd < 0){
                while (1){
                    printf("Numero invalido!\n");
                    printf("Redigite, por favor: ");
                    scanf("%d", &qtd);
                    if (qtd == 0){
                        printf("Cancelando craft...\n");
                        break;
                    }else if(qtd > 0){
                        break;
                    }
                }
            }
            if (qtd > 0){
                if (qtd * 6 > *herb){
                    printf("A quantidade de ervas eh insuficiente\n");
                }else{
                    for (c = 0; c < qtd; c++){
                        *mhpotion += 1;
                    }
                    printf("%s criou %d mega pocoes", personagem, qtd);
                }
            }
        break;
        
        case 3:
            if (*confesp == 0){
                printf("Espada da Masmorra\n");
                printf("A lendaria espada da masmorra concede um bonus de ataque para quem a utiliza\n");
                printf("Preco: 100 ossos\n");
                printf("1 - Fazer Espada da Masmorra\n");
                printf("2 - Na volta a gente compra\n");
                scanf("%d", &esc);
                while (esc < 1 || esc > 2){
                    printf("Opcao invalida\n");
                    printf("Redigite, por favor: ");
                    scanf("%d", &esc);
                }
                switch (esc){
                    case 1:
                        if (*ossos < 100){
                            printf("Ossos insuficientes!\n");
                        }else{
                            *confesp = 1;
                            *ossos -= 100;
                            *atk += 20;
                        }

                    case 2:
                        printf("Cancelando craft...\n");
                }
            }else{
                printf("Parabens! Voce ja possui a Espada da Masmorra\n");
            }
        break;

        case 4:
            if (*confarc == 0){
                printf("Arco da Floresta\n");
                printf("O mistico Arco da Floresta aumenta o ataque de quem o empunha\n");
                printf("Preco: 80 ervas\n");
                printf("1 - Fazer Arco da Floresta\n");
                printf("2 - Na volta a gente compra\n");
                scanf("%d", &esc);
                while (esc < 1 || esc > 2){
                    printf("Opcao invalida\n");
                    printf("Redigite, por favor: ");
                    scanf("%d", &esc);
                }
                switch (esc){
                    case 1:
                        if (*herb < 80){
                            printf("Ervas insuficientes!\n");
                        }else{
                            *confarc = 1;
                            *herb -= 80;
                            *atk += 15;
                        }

                    case 2:
                        printf("Cancelando craft...\n");
                }
            }else{
                printf("Parabens! Voce ja possui o Arco da Floresta\n");
            }
        break;
    }
}

void vasculhar(int amb, int *hp, int *herb, int *hpotion, int *mhpotion, int *ossos, int *atk, char personagem[]){

    int numsort, qtd;
    switch (amb){

        case 2:
            numsort = rand();
            numsort = numsort % 10;
            qtd = rand();
            qtd = qtd % 10;
            if (qtd == 0){
                qtd = 1;
            }else if (qtd > 6){
                qtd -= 3;
            }
            if (numsort < 4){
                printf("Uepa! Ervinhas!\n");
                printf("%s recebe %d erva(s)\n", personagem, qtd);
                *herb += qtd;
            }else if (numsort < 8){
                printf("Eita sor! Pocao!\n");
                printf("%s recebe %d pocao(oes)\n", personagem, qtd);
                *hpotion += qtd;
            }
            else if (numsort < 9){
                printf("Sassenhora, uma mega pocao!\n");
                printf("%s recebe uma megapocao\n", personagem);
                *mhpotion += 1;
            }else{
                printf("O bicho sortudo ein, um bonus de vida!\n");
                printf("%s recebe 5 pontos de vida\n", personagem);
                *hp += 5;
            }
        break;

        case 3:
            numsort = rand();
            numsort = numsort % 10;
            qtd = rand();
            qtd = qtd % 10;
            if (qtd == 0){
                qtd = 1;
            }else if (qtd > 6){
                qtd -= 3;
            }
            if (numsort < 6){
                printf("URGHH! Ossos!\n");
                printf("%s recebe %d osso(s)\n", personagem, qtd);
                *ossos += qtd;
            }else if (numsort < 9){
                printf("Oloco meu! Ponto de ataque!\n");
                printf("%s recebe 1 ponto de ataque\n", personagem);
                *atk += 1;
            }else{
                printf("Sem escandalo fml, saca so, altos ponto de ataque!\n");
                printf("%s recebe 5 pontos de ataque\n", personagem);
                *atk += 5;
            }
        break;
    }
    return;
}

void atacar(int amb, int *hp, int *atk, int *morte, int *hpotion, int *mhpotion, int *ossos, int *herb, char personagem[]){
    int hpbat, hpini, atkini, numsort, dado, esc;
    int atkiniflo[5] = {6, 9, 7, 4, 6};
    int hpiniflo[5] = {50, 70, 40, 30, 55};
    char inimigosfloresta[10][30] = {"Goblin", "Druida", "Duende", "Cobra", "Aranha Gigante"};
    int atkinidun[5] = {6, 6, 8, 10, 5};
    int hpinidun[5] = {40, 40, 55, 70, 60};
    char inimigosdungeon[5][30] = {"Esqueleto", "Zumbi", "Espirito", "Demonio", "Gangue de Ratos"};
    char inimigo[30];
    hpbat = *hp;
    switch (amb){

        case 2:
            numsort = rand();
            numsort = numsort % 10;
            switch (numsort){

                case 0:
                    hpini = hpiniflo[0];
                    atkini = atkiniflo[0];
                    strcpy(inimigo, inimigosfloresta[0]);
                    break;
                
                case 1:
                    hpini = hpiniflo[1];
                    atkini = atkiniflo[1];
                    strcpy(inimigo, inimigosfloresta[1]);
                    break;

                case 2:
                    hpini = hpiniflo[2];
                    atkini = atkiniflo[2];
                    strcpy(inimigo, inimigosfloresta[2]);
                    break;

                case 3:
                    hpini = hpiniflo[3];
                    atkini = atkiniflo[3];
                    strcpy(inimigo, inimigosfloresta[3]);
                    break;

                default:
                    hpini = hpiniflo[4];
                    atkini = atkiniflo[4];
                    strcpy(inimigo, inimigosfloresta[4]);
            }
            printf("A batalha entre %s e %s comeca!\n", personagem, inimigo);
            while ((hpbat > 0) && (hpini > 0)){
                printf("----------------------------------------------------------------------------------\n");
                dado = rand();
                dado = dado % 10;
                if (dado < 5){
                    printf("%s ataca primeiro\n", personagem);
                    printf("1 - Usar pocao\n");
                    printf("2 - Atacar\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &esc);
                    while (esc < 1 || esc > 2){
                        printf("Opcao invalida!\n");
                        printf("Redigite, por favor: ");
                        scanf("%d", &esc);
                    }
                    switch (esc){

                        case 1:
                            printf("1 - Pocao normal\n");
                            printf("2 - Mega pocao\n");
                            printf("Escolha uma opcao: ");
                            scanf("%d", &esc);
                            while (esc < 1 || esc > 2){
                                printf("Opcao invalida!\n");
                                printf("Redigite, por favor: ");
                                scanf("%d", &esc);
                            }
                            switch (esc){

                                case 1:
                                    if (*hpotion > 0){
                                        hpbat += 20;
                                        *hpotion -= 1;
                                    }else{
                                        printf("Pocoes insuficientes!\n");
                                    }
                                    break;

                                case 2:
                                    if (*mhpotion > 0){
                                        hpbat += 50;
                                        *mhpotion -= 1;
                                    }else{
                                        printf("Mega pocoes insuficientes!\n");
                                    }
                                    break;
                            }
                            break;

                        case 2:
                            switch (dado){
                                case 2:
                                    printf("%s errou o ataque, que pamonha\n", personagem);
                                    break;

                                case 5:
                                    printf("%s atacou e acertou na furia, dano critico!\n", personagem);
                                    hpini -= *atk * 2;
                                    break;

                                case 8:
                                    printf("%s atacou e passou longe, muito longe\n", personagem);
                                    break;

                                default:
                                    printf("So paulada de %s\n", personagem);
                                    hpini -= *atk;
                                    break;
                            }
                    }
                }else{
                    printf("%s ataca primeiro\n", inimigo);
                    switch (dado){
                        case 1:
                            printf("%s errou o ataque, moscou\n", inimigo);
                            break;

                        case 4:
                            printf("%s martelou, dano critico!\n", inimigo);
                            hpbat -= atkini * 2;
                            break;

                        case 7:
                            printf("%s ta meio doido, errou feio\n", inimigo);
                            break;
                        
                        default:
                            printf("linda paulada %s\n", inimigo);
                            hpbat -= atkini;
                            break;
                        }
                    }
                printf("----------------------------------------------------------------------------------\n");
                if (dado < 5){
                   printf("%s ataca agora\n", inimigo);
                   switch(dado){
                       case 1:
                            printf("%s errou o ataque, moscou\n", inimigo);
                            break;


                        case 4:
                            printf("%s martelou, dano critico!\n", inimigo);
                            hpbat -= atkini * 2;
                            break;


                        case 7:
                            printf("%s ta meio doido, errou feio\n", inimigo);
                            break;
                        
                        default:
                            printf("linda paulada %s\n", inimigo);
                            hpbat -= atkini;
                            break;
                        
                    }
                }else{
                    printf("%s ataca agora\n", personagem);
                    printf("1 - Usar pocao\n");
                    printf("2 - Atacar\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &esc);
                    while (esc < 1 || esc > 2){
                        printf("Opcao invalida!\n");
                        printf("Redigite, por favor: ");
                        scanf("%d", &esc);
                    }
                    switch (esc){

                        case 1:
                            printf("1 - Pocao normal\n");
                            printf("2 - Mega pocao\n");
                            printf("Escolha uma opcao: ");
                            scanf("%d", &esc);
                            while (esc < 1 || esc > 2){
                                printf("Opcao invalida!\n");
                                printf("Redigite, por favor: ");
                                scanf("%d", &esc);
                            }
                            switch (esc){

                                case 1:
                                    if (*hpotion > 0){
                                        hpbat += 20;
                                        *hpotion -= 1;
                                    }else{
                                        printf("Pocoes insuficientes!\n");
                                    }
                                    break;

                                case 2:
                                    if (*mhpotion > 0){
                                        hpbat += 50;
                                        *mhpotion -= 1;
                                    }else{
                                        printf("Mega pocoes insuficientes!\n");
                                    }
                                    break;
                            }
                            break;

                        case 2:
                            switch(dado){
                                case 2:
                                    printf("%s errou o ataque, que pamonha\n", personagem);
                                    break;

                                case 5:
                                    printf("%s atacou e acertou na furia, dano critico!\n", personagem);
                                    hpini -= *atk * 2;
                                    break;

                                case 8:
                                    printf("%s atacou e passou longe, muito longe\n", personagem);
                                    break;

                                default:
                                    printf("So paulada de %s\n", personagem);
                                    hpini -= *atk;
                                    break;
                            }
                    }
                }
                printf("Sua vida: %d\n", hpbat);
                printf("Vida do inimigo: %d\n", hpini);
                printf("----------------------------------------------------------------------------------\n");
            }
            if (hpbat > 0){
                printf("Voce venceu!\n");
                numsort = rand();
                numsort = numsort % 10;
                if (numsort == 0){
                    numsort = 1;
                }else if (numsort > 6){
                    numsort -= 2;
                }
                *herb += numsort;
                printf("%s matou %s e recebeu %d ervas!\n", personagem, inimigo, numsort);
            }else{
                printf("Voce morreu!");
                *morte = 1;
            }
            break;

        case 3:
            numsort = rand();
            numsort = numsort % 10;
            switch (numsort){

                case 0:
                    hpini = hpinidun[0];
                    atkini = atkinidun[0];
                    strcpy(inimigo, inimigosdungeon[0]);
                    break;
                
                case 1:
                    hpini = hpinidun[1];
                    atkini = atkinidun[1];
                    strcpy(inimigo, inimigosdungeon[1]);
                    break;

                case 2:
                    hpini = hpinidun[2];
                    atkini = atkinidun[2];
                    strcpy(inimigo, inimigosdungeon[2]);
                    break;

                case 3:
                    hpini = hpinidun[3];
                    atkini = atkinidun[3];
                    strcpy(inimigo, inimigosdungeon[3]);
                    break;

                default:
                    hpini = hpinidun[4];
                    atkini = atkinidun[4];
                    strcpy(inimigo, inimigosdungeon[4]);
            }
            printf("A batalha entre %s e %s comeca\n", personagem, inimigo);
            while ((hpbat > 0) && (hpini > 0)){
                dado = rand();
                dado = dado % 10;
                if (dado < 5){
                    printf("%s ataca primeiro\n", personagem);
                    printf("1 - Usar pocao\n");
                    printf("2 - Atacar\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &esc);
                    while (esc < 1 || esc > 2){
                        printf("Opcao invalida!\n");
                        printf("Redigite, por favor: ");
                        scanf("%d", &esc);
                    }
                    switch (esc){

                        case 1:
                            printf("1 - Pocao normal\n");
                            printf("2 - Mega pocao\n");
                            printf("Escolha uma opcao: ");
                            scanf("%d", &esc);
                            while (esc < 1 || esc > 2){
                                printf("Opcao invalida!\n");
                                printf("Redigite, por favor: ");
                                scanf("%d", &esc);
                            }
                            switch (esc){

                                case 1:
                                    if (*hpotion > 0){
                                        hpbat += 20;
                                        *hpotion -= 1;
                                    }else{
                                        printf("Pocoes insuficientes!\n");
                                    }
                                    break;

                                case 2:
                                    if (*mhpotion > 0){
                                        hpbat += 50;
                                        *mhpotion -= 1;
                                    }else{
                                        printf("Mega pocoes insuficientes!\n");
                                    }
                                    break;
                            }
                            break;
                        
                        case 2:
                            switch (dado){
                                case 2:
                                    printf("%s errou o ataque, que pamonha\n", personagem);
                                    break;

                                case 5:
                                    printf("%s atacou e acertou na furia, dano critico!\n", personagem);
                                    hpini -= *atk * 2;
                                    break;

                                case 8:
                                    printf("%s atacou e passou longe, muito longe\n", personagem);
                                    break;

                                default:
                                    printf("So paulada de %s\n", personagem);
                                    hpini -= *atk;
                                    break;
                            }
                        }
                }else{
                    printf("%s ataca primeiro\n", inimigo);
                    switch (dado){
                        case 1:
                            printf("%s errou o ataque, moscou\n", inimigo);
                            break;

                        case 4:
                            printf("%s martelou, dano critico!\n", inimigo);
                            hpbat -= atkini * 2;
                            break;

                        case 7:
                            printf("%s ta meio doido, errou feio\n", inimigo);
                            break;
                        
                        default:
                            printf("linda paulada %s\n", inimigo);
                            hpbat -= atkini;
                            break;
                    }
               }
               if (dado < 5){
                   printf("%s ataca agora\n", inimigo);
                   switch(dado){
                       case 1:
                            printf("%s errou o ataque, moscou\n", inimigo);
                            break;

                        case 4:
                            printf("%s martelou, dano critico!\n", inimigo);
                            hpbat -= atkini * 2;
                            break;

                        case 7:
                            printf("%s ta meio doido, errou feio\n", inimigo);
                            break;
                        
                        default:
                            printf("linda paulada %s\n", inimigo);
                            hpbat -= atkini;
                            break;
                        
                    }
                }else{
                    printf("%s ataca agora\n", personagem);
                    printf("1 - Usar pocao\n");
                    printf("2 - Atacar\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &esc);
                    while (esc < 1 || esc > 2){
                        printf("Opcao invalida!\n");
                        printf("Redigite, por favor: ");
                        scanf("%d", &esc);
                    }
                    switch (esc){

                        case 1:
                            printf("1 - Pocao normal\n");
                            printf("2 - Mega pocao\n");
                            printf("Escolha uma opcao: ");
                            scanf("%d", &esc);
                            while (esc < 1 || esc > 2){
                                printf("Opcao invalida!\n");
                                printf("Redigite, por favor: ");
                                scanf("%d", &esc);
                            }
                            switch (esc){

                                case 1:
                                    if (*hpotion > 0){
                                        hpbat += 20;
                                        *hpotion -= 1;
                                    }else{
                                        printf("Pocoes insuficientes!\n");
                                    }
                                    break;

                                case 2:
                                    if (*mhpotion > 0){
                                        hpbat += 50;
                                        *mhpotion -= 1;
                                    }else{
                                        printf("Mega pocoes insuficientes!\n");
                                    }
                                    break;
                            }
                            break;
                        
                        case 2:
                            switch(dado){
                                case 2:
                                    printf("%s errou o ataque, que pamonha\n", personagem);
                                    break;

                                case 5:
                                    printf("%s atacou e acertou na furia, dano critico!\n", personagem);
                                    hpini -= *atk * 2;
                                    break;

                                case 8:
                                    printf("%s atacou e passou longe, muito longe\n", personagem);
                                    break;

                                default:
                                    printf("So paulada de %s\n", personagem);
                                    hpini -= *atk;
                                    break;
                            }
                    }
                }
                printf("Sua vida: %d\n", hpbat);
                printf("Vida do inimigo: %d\n", hpini);
            }
            if (hpbat > 0){
                printf("Voce venceu!\n");
                numsort = rand();
                numsort = numsort % 10;
                if (numsort == 0){
                    numsort = 1;
                }else if (numsort > 6){
                    numsort -= 2;
                }
                *ossos += numsort;
                printf("%s matou %s e recebeu %d ossos!\n", personagem, inimigo, numsort);
            }else{
                printf("Voce morreu!");
                *morte = 1;
            }
            break;
    }
    return;
}

void fugir(int amb, int *hp, int *atk, int *morte, int *hpotion, int *mhpotion, int *ossos, int *herb, char personagem[]){
    int numsort;
    numsort = rand();
    numsort = numsort % 10;
    switch(numsort){

        case 3:
            printf("%s falhou em fugir, agora vai a luta\n", personagem);
            atacar(amb, hp, atk, *&morte, *&hpotion, *&mhpotion, *&ossos, *&herb, personagem);
            break;

        case 9:
            printf("%s tentou fugir, mas falhou miseravelmente\n", personagem);
            atacar(amb, hp, atk, *&morte, *&hpotion, *&mhpotion, *&ossos, *&herb, personagem);
            break;

        default:
            printf("%s fugiu fugido fugidinho\n", personagem);
            break;
    }
    return;
}

void andar(int amb, int *hp, int *atk, int *morte, int *hpotion, int *mhpotion, int *ossos, int *herb, char personagem[]){
    int numsort, esc;
    switch (amb){

        case 2:
            numsort = rand();
            numsort = numsort % 10;
            switch (numsort){
            case 0:
                printf("Caminhando tranquilamente pela floresta...\n");
                break;

            case 1:
                printf("O sol esta radiante hoje, ein?\n");
                break;

            case 2:
                printf("Vou dar uma corridinha pra ficar fitness\n");
                break;

            case 3:
                printf("*Tropeca num graveto* O DESGRAMA QUEM BOTO ESSE TREM AQUI\n");
                break;

            case 4:
                printf("Olha os passarin que bicho bunito sor\n");
                break;
            
            case 5:
                printf("NAO CREIO QUE PISEI NA BOSTA\n");
                break;

            case 6: 
                printf("*Canta enquanto caminha* Eu to voando altoooo\nFico na minha luta e trabalhador dobrado, eh\nTodo o show elas ta me querendo\nSabe que o Poze eh o cara do momento\n");
                break;
            
            case 7:
                printf("Hmmmm vou comer aquelas amorinha ali\n");
                break;

            case 8:
                printf("Andando a meia hora sem wifi nessa desgracaaaa\n");
                break;

            case 9:
                printf("%s encontra um inimigo\n", personagem);
                printf("Escolha uma opcao:\n");
                printf("1 - Atacar\n");
                printf("2 - Fugir\n");
                scanf("%d", &esc);
                while (esc < 1 || esc > 2){
                    printf("Opcao invalida!\n");
                    printf("Redigite, por favor: ");
                    scanf("%d", &esc);
                }
                switch (esc){
                    case 1:
                        atacar(amb, *&hp, *&atk, *&morte, *&hpotion, *&mhpotion, *&ossos, *&herb, personagem);
                        break;
                    
                    case 2:
                        fugir(amb, *&hp, *&atk, *&morte, *&hpotion, *&mhpotion, *&ossos, *&herb, personagem);
                        break;
                }
            }
            break;
        
        case 3:
            numsort = rand();
            numsort = numsort % 10;
            switch (numsort){
            case 0:
                printf("Descendo as escadarias da masmorra...\n");
                break;
            
            case 1:
                printf("Escuro pra dedeu aqui\n");
                break;

            case 2:
                printf("*Pisa em um esqueleto* Po foi mal ai meu camarada, espero que nao tenha machucado\n");
                break;

            case 3:
                printf("*Tropeca em um osso* AAAAOOOOOO DISGRAMA\n");
                break;

            case 4:
                printf("Fala tu ratatouille, na moral?\n");
                break;

            case 5:
                printf("Que lugar grande da pega\n");
                break;


            case 6:
                printf("*Pisa na lama* Agora que meus sapato se escafedeceu\n");
                break;

            case 7:
                printf("*Cantarolando* Se voce e jovem ainda, jovem ainda, jovem ainda\nAmanha velho sera¡, velho sera¡, velho sera¡!\nA menos que o coracao, que o coracao sustente\nA juventude que nunca morrera¡!\n");
                break;

            case 8:
                printf("Onde e que estou? Sera que estou em Lagoinha?\n");
                break;

            case 9:
                printf("%s encontra um inimigo\n", personagem);
                printf("Escolha uma opcao:\n");
                printf("1 - Atacar\n");
                printf("2 - Fugir\n");
                scanf("%d", &esc);
                while (esc < 1 || esc > 2){
                    printf("Opcao invalida!\n");
                    printf("Redigite, por favor: ");
                    scanf("%d", &esc);
                }
                switch (esc){
                    case 1:
                        atacar(amb, *&hp, *&atk, *&morte, *&hpotion, *&mhpotion, *&ossos, *&herb, personagem);
                        break;
                    
                    case 2:
                        fugir(amb, *&hp, *&atk, *&morte, *&hpotion, *&mhpotion, *&ossos, *&herb, personagem);
                        break;
                }
                break;
            }
        break;
    }
    return;
}

int option(int amb, int op, int *cansado, int *hp, int *herb, int *hpotion, int *mhpotion, int *ossos, int *atk, int *pmorte, int *confesp, int *confarc, char personagem[]){
    int c;
    int inv[6] = {*hp, *atk, *herb, *hpotion, *mhpotion, *ossos};
    char invnames[6][30] = {"HP: ", "ATK: ", "Ervas: ", "Pocao de Cura: ", "Megapocao de Cura: ", "Ossos: "};
    switch (amb){
    
      case 1:
      switch (op){
      
        case 1:
            printf("Entrando na floresta...\n");
            return 2;
            break;
      
        case 2:
            printf("Entrando na dungeon...\n");
            return 3;
            break;
          
        case 3:
            printf("Exibindo o inventario...\n");
            for (c = 0; c < 6; c++){
                printf("%s", invnames[c]);
                printf("%d\n", inv[c]);
            }
            return amb;
            break;
          
        case 4:
            printf("Entrando no menu de craft...\n");
            craft(*&atk, *&herb, *&hpotion, *&mhpotion, *&ossos, *&confesp, *&confarc, personagem);
            return amb;
            break;
      }
      case 2:
      if (*cansado > 0){
        switch(op){
        
            case 1:
                printf("Voltando pra casa...\n");
                *cansado = rand();
                *cansado = *cansado % 10;
                if (*cansado == 0){
                    *cansado = 2;
                }
                return 1;
                break;
            
            case 2:
                printf("Caminhando pela floresta...\n");
                andar(amb, hp, atk, *&pmorte, *&hpotion, *&mhpotion, *&ossos, *&herb, personagem);
                *cansado -= 1;
                return amb;
                break;
            
            case 3:
                printf("Vasculhando os arbustos...\n");
                vasculhar(amb, *&hp, *&herb, *&hpotion, *&mhpotion, *&ossos, *&atk, personagem);
                *cansado -= 1;
                return amb;
                break;
            
            case 4:
                printf("Exibindo o inventario...\n");
                for (c = 0; c < 6; c++){
                    printf("%s", invnames[c]);
                    printf("%d\n", inv[c]);
                }
                return amb;
                break;
            
            case 5:
                printf("Entrando no menu de craft...\n");
                craft(*&atk, *&herb, *&hpotion, *&mhpotion, *&ossos, *&confesp, *&confarc, personagem);
                return amb;
                break;
        }
      }else{
            printf("Voltando para casa...\n");
            *cansado = rand();
            *cansado = *cansado % 10;
            if (*cansado == 0){
                *cansado = 2;
            }
            return 1;
      }
      break;
        
      case 3:
      if (*cansado > 0){
        switch (op){
        case 1:
            printf("Voltando pra casa...\n");
            *cansado = rand();
            *cansado = *cansado % 10;
            if (*cansado == 0){
                *cansado = 2;
            }
            return 1;
            break;
            
        case 2:
            printf("Andando pela masmorra...\n");
            andar(amb, hp, atk, *&pmorte, *&hpotion, *&mhpotion, *&ossos, *&herb, personagem);
            *cansado -= 1;
            return amb;
            break;
            
        case 3:
            printf("Vasculhando cadaver...\n");
            vasculhar(amb, *&hp, *&herb, *&hpotion, *&mhpotion, *&ossos, *&atk, personagem);
            *cansado -= 1;
            return amb;
            break;
        
        case 4:
            printf("Exibindo o inventario...\n");
            for (c = 0; c < 6; c++){
                printf("%s", invnames[c]);
                printf("%d\n", inv[c]);
            }
            return amb;
            break;
          
        case 5:
            printf("Entrando no menu de craft...\n");
            craft(*&atk, *&herb, *&hpotion, *&mhpotion, *&ossos, *&confesp, *&confarc, personagem);
            return amb;
            break;
        }
      }else{
            printf("Voltando para casa...\n");
            *cansado = rand();
            *cansado = *cansado % 10;
            if (*cansado == 0){
                *cansado = 2;
            }
            return 1;
        }
        break;
    return amb;
    }
}

int main(){
    srand(time(NULL));
    int hp = 60, hpotion = 0, mhpotion = 0, herb = 0, ossos = 0, atk = 5, esc = 0, amb = 1, op, maxop, morte = 0, confesp = 0, confarc = 0, cansado = rand();
    char personagem[40];
    cansado = cansado % 10;
    if (cansado == 0){
        cansado = 2;
    }
    printf("Um jogo feito por: Farias, Betao, Nico e Daniel Otaku\n");
    printf("Escolha seu personagem:\n");
    printf("1 - Robson, o Pinscher\n");
    printf("2 - Lula, o ladrao que roubou meu coracao\n");
    printf("3 - Agostinho Carrara, o taxista\n");
    printf("4 - Jose, o Abacate\n");
    printf("5 - Barbara Millicent 'Barbie' Roberts\n");
    printf("6 - Criar seu personagem\n");
    printf("Escolha seu personagem: ");
    scanf("%d", &esc);
    while (esc < 1 || esc > 6){
        printf("Numero invalido!\n");
        printf("Redigite por favor: ");
        scanf("%d", &esc);
    }
    switch (esc){
            case 1:
            strcpy(personagem, "Robson, o Pinscher");
            printf("%s, a historia:\n", personagem);
            printf("Robson era um pinscher muito amado, ate o tragico dia que sua familia viajou e nunca mais retornou...\nRobson vive em uma casinha ao pe de uma montanha, sozinho, na escuridao.\n\nAte que um dia Robson resolveu deixar essa vida e se aventurar pela floresta,\n agora voce sera o responsavel pela nova historia de Robson!\n");
            break;

            case 2:
            strcpy(personagem, "Lula, o ladrao (de <3)");
            printf("%s, a historia:\n", personagem);
            printf("Desde crianca, Lula acredita que seu numero da sorte seja 13.\nAos 17 anos (numero de sua ma sorte) perdeu seu dedo enquanto batia carteira.\nAgora ele age tal como um Hobin Hood da modernidade, roubando dos pobres e dando pros ricos.\n");
            break;

            case 3:
            strcpy(personagem,"Agostinho Carrara, o taxista");
            printf("%s, a historia:\n", personagem);
            printf("Agostinho Carrara, jovem trabalhador e residente da baixada fluminense no Rio de Janeiro,\nprocurava dinheiro para pagar seu sogro Lineu, o paulao da mecanica, suas dividas na sinuca e comprar uns presentes pra Bebel.\nAjude Agostinho a passar a perna em muitos malandrinhos\ne faturar uma grana para quitar suas dividas e apostar no bicho!\n");
            break;

            case 4:
            strcpy(personagem, "Jose, o abacate");
            printf("%s, a historia:\n", personagem);
            printf("Jose sempre se achou diferente de seus companheiros.\nSendo criado na roca, almejava por uma vida mais agitada.\nApos sua família ser raptada e morta pelo agricultor mexicano, ele procura honra-los se aventurando.\n");
            break;

            case 5:
            strcpy(personagem, "Barbie");
            printf("%s, a historia:\n", personagem);
            printf("Apos ter graduacao em 34.987 cursos, especializacao em 32.876 e experiencia em 40.902 profissoes,\nBarbie esta prestes a enfrentar algo que nunca havia visto antes: uma aventura em dungeons.\nAjude a Barbie a completar essa ultima missao, para que ela realmente tenha o titulo de multifuncional.\n");
            break;

            case 6:
            printf("Nome do personagem: ");
            scanf("%s", personagem);
            break;
    }
    printf("JOGO INICIANDO...\n");
    while (1){
        printf("----------------------------------------------------------------------------------\n");
        maxop = ondeesta(amb, &cansado); 
        ambiente(amb, &cansado, personagem);
        printf("Opcao: ");
        scanf("%d", &op);
        while (op < 0 || op > maxop){
            printf("Opcao invalida!\n");
            printf("Redigite, por favor: ");
            scanf("%d", &op);
        }
        if (op == 0){
            break;
        }
        amb = option(amb, op, &cansado, &hp, &herb, &hpotion, &mhpotion, &ossos, &atk, &morte, &confesp, &confarc, personagem);
        if (morte == 1){
            break;
        }
        printf("----------------------------------------------------------------------------------\n");
    }
    printf("JOGO FINALIZANDO...\n");
    printf("Obrigado por jogar o nosso jogo :)\n");
    printf("Se curtirem nosso game, votem na gente, somos o Grupo 1 - Los Mejores!");
    return 0;
}