GCLASS(IBattleArea) = [
    ["#type","IBattleArea"],
    ["id",-1],
    ["name",""],
    ["position",nil],
    ["FindFebaInside", {params["_side"];}],
    ["GetPosition",{}],
    ["CreateAreaInfo",{
        private _id = _self get "id";
        private _name = _self get "name";
        private _position = _self get "position";
        createHashMapObject[GCLASS(AreaInfo),[_id,_name,_position]];
    }]
];