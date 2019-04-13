#include "expert_system.h"

int status_letter(t_expert *data, char *s, int i)
{
    if (find(data, s[i], STAT) && !NOT(s[i - 1]) && !XOR(s[i - 1]) && !AND(s[i - 1]))
    {
        return (TRUE);
    }
    else if (find(data, s[i - 1], FACT))
    {
        return (TRUE);
    }
    return (FALSE);
}

void status_brackets(t_expert *data, char *s, int i, int *status)
{
    int prev;

    prev = FALSE;
    if (s[i] == '(')
    {
        prev = (TRUE == NOT(s[i - 1]) ? TRUE : FALSE);
        *status = rules_is_true(data, s + i + 1, *status, TRUE);
        while(s[i] && s[i] != ')')
        {
            i++;
        }
        if (prev)
        {
            *status = (TRUE == *status ? FALSE : TRUE);
        }
    }
}

void status_and(t_expert *data, char *s, int i, int *status)
{
    if (TRUE == *status)
    {
        if (TRUE == LETTER(s[i + 1]) && FALSE == find(data, s[i + 1], STAT))
        {
            *status = FALSE;
        }
        else if (TRUE == NOT(s[i + 1]) && TRUE == find(data, s[i + 2], STAT))
        {
            *status = FALSE;
        }
    }
    else
    {
        *status = FALSE;
    }
}

int status_OR(t_expert *data, char *s, int i, int *status)
{
    if (FALSE == *status)
    {
        if (TRUE == LETTER(s[i + 1]) && TRUE == find(data, s[i + 1], STAT))
        {
            ft_printf("OR %c\n", s[i + 1]);
            *status = TRUE;
        }
        /**/
        else if (FALSE == find(data, s[i + 2], STAT))
        {
            ft_printf("1OR %c\n", s[i + 2]);
            *status = TRUE;
        }/**/
        return(TRUE); 
    }
    return (FALSE);
}

void status_XOR(t_expert *data, char *s, int i, int *status)
{
    if (TRUE == *status)
    {
        if (TRUE == find(data, s[i + 1], STAT) && FALSE == find(data, s[i + 1], FACT))
        {
            *status = FALSE;
        }
        else if (TRUE == NOT(s[i + 1]) && FALSE == find(data, s[i + 2], STAT))
        {
            *status = FALSE;
        }
    }
    else
    {
        if (TRUE == find(data, s[i + 1], STAT))
        {
            *status = TRUE;
        }
        else if (TRUE == NOT(s[i + 1]) && FALSE == find(data, s[i + 2], STAT))
        {
            *status = TRUE;
        }
    }
}