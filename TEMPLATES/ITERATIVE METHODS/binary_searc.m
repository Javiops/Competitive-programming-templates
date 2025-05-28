function root = bisectionMethod(f, a, b, tol, max_iter)
    % Finds a root of f(x) = 0 using the Bisection Method
    % Inputs:
    %   f         - function handle
    %   a, b      - interval endpoints
    %   tol       - tolerance (stopping condition)
    %   max_iter  - maximum number of iterations
    % Output:
    %   root      - approximate root of f
    
    if f(a) * f(b) > 0
        error('f(a) and f(b) must have opposite signs');
    end

    for k = 1:max_iter
        c = (a + b) / 2;
        if abs(f(c)) < tol || (b - a) / 2 < tol
            root = c;
            return;
        end

        if f(a) * f(c) < 0
            b = c;
        else
            a = c;
        end
    end

    root = (a + b) / 2;  % Final approximation after max_iter
end
