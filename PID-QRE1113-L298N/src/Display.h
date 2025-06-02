#ifndef DISPLAY_H
#define DISPLAY_H

void display(const char *titulo, const char *valor, bool menuAnterior, bool menuPosterior);
void display(const char *titulo);
bool faixaDeMenus(short valorMenu);
void iniciarDisplay();
void limparDisplay();

#endif
