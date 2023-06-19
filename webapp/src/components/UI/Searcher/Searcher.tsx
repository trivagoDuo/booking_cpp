"use client";
import React from "react";
import Image from "next/image";

const Searcher = () => {
    return(
        <div className="relative rounded-full bg-white shadow-sm drop-shadow-none hover:drop-shadow">
            <Image src="/search.svg" alt="search" width={20} height={20}
                className="absolute top-2.5 left-2"/>
            <input
                type="text"
                name="search"
                id="search"
                placeholder="Поиск по сайту"
                className={`outline-0 rounded-full py-2 px-4 block w-full appearance-none
                leading-normal`}
                style={{paddingLeft: "2.5rem"}}
            />
        </div>
    )
}

export default Searcher;