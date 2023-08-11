        double f_b = function(b);
        double f_c = function(c);

        cout << i << "\t\t" << a << "\t\t" << b << "\t\t" << f_a << "\t\t" << f_b << endl;

        if (f_c == 0.0 || (b - a) / 2.0 < 0.0001) {
            cout << "Root found: " <<