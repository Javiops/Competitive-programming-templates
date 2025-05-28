function root = newtonMethod(f, df, x0, tolx, tolf, maxit)
    % Newton-Raphson method to find a root of f(x) = 0

    l = tolx + 1;  % initialize l to enter the loop
    n = 1;
    x = x0;

    while (n < maxit && l > tolx)
        fx = f(x);
        dfx = df(x);

        if dfx == 0
            error("Derivative is zero. Newton''s method fails.");
        end

        x_new = x - fx / dfx;

        if abs(f(x_new)) < tolf
            l = 0;  % root is accurate enough
        else
            l = abs(x_new - x);
        end

        x = x_new;
        n = n + 1;
    end

    root = x;  % return final approximation
end
