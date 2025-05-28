function root = bisectionFixedStyle(f, a, b, tolx, tolf, maxit)
    %    This function uses bolzano's theorem

    if f(a) * f(b) > 0
        error("The function needs to change sign at [a, b]");
    end
    
    l = abs(a - b);
    n = 1;
    x = a;  % x1 = a

    while (n < maxit && l > tolx)
        x_new = 0.5 * (a + b);

        if abs(f(x_new)) < tolf
            l = 0;  % Root is good enough, stop
        else
            if f(a) * f(x_new) < 0
                b = x_new;
            else
                a = x_new;
            end
            l = abs(x_new - x);  % Update step size
        end

        x = x_new;
        n = n + 1;
    end

    root = x;  % Final approximation
end
