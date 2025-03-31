GCLASS(IDIssuer) = [
    ["idCounter",-1],
    ["#create",{
    }],
    ["Issue",{
        private _newID = (_self get "idCounter") + 1;
        _self set ["idCounter",_newID];
        _self get "idCounter";
    }]
];