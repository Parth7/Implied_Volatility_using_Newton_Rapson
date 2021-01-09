//
// Created by Parth Parakh on 08/01/21.
//

#include<cmath>

template<typename D,class T, D(T::*g)(D) const, D(T::*g_prime)(D) const>
D newton_rapson(D y_target, D init, D epsilon, const T& root_func)
{
    D y = (root_func.*g)(init);
    D x = init;

/*
     * \begin{eqnarray}\sigma_{n+1} = \frac{C_M - B(\sigma_n)}{\frac{\partial B}{\partial \sigma} (\sigma_n)} + \sigma_n\end{eqnarray}
     *
     * \begin{eqnarray}x_{n+1} = \frac{y - g(x_n)}{g'(x_n)} + x_n\end{eqnarray}
     */

    while (fabs(y-y_target) > epsilon)
    {
        D d_x = (root_func.*g_prime)(x);
        x += (y_target-y)/d_x;
        y = (root_func.*g)(x);
    }
    return x;
}
