#ifndef DISPLAY_H
#define DISPLAY_H

void display(char *titulo, char *valor, bool menuAnterior, bool menuPosterior);
void display(char *titulo);
bool faixaDeMenus(short valorMenu);
void iniciarDisplay();
void limparDisplay();

#endif
