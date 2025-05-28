function root = secantMethod(f, x0, x1, tolx, tolf, maxit)
    % Secant method to find a root of f(x) = 0

    l = abs(x1 - x0);  % initial difference
    n = 1;

    while (n < maxit && l > tolx)
        fx0 = f(x0);
        fx1 = f(x1);

        if fx1 == fx0
            error("Division by zero in secant method");
        end

        x_new = (x0 * fx1 - x1 * fx0) / (fx1 - fx0);

        if abs(f(x_new)) < tolf
            l = 0;
        else
            l = abs(x_new - x1);
        end

        x0 = x1;
        x1 = x_new;
        n = n + 1;
    end

    root = x1;
end
