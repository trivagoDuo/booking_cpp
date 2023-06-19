import React from "react";

export default function Page({params} : {params: {id: string}}) {
    return(
        <div>
            <h1>Room {params.id}</h1>
        </div>
    )
}