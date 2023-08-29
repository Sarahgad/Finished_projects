#include "main.h"
/**
 *main - entry point
 *Description: simple shell
 *Return: 0 always success
 */
int main(void)
{
if (!isatty(STDIN_FILENO))
{
non_interactive();
}
else
{
interactive();

}
return (0);
}
