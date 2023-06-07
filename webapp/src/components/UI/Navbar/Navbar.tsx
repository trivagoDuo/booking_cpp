import React from "react";
import Link from "next/link";
import Image from "next/image";
import Searcher from "@/components/UI/Searcher/Searcher";

const Navbar = () => {
    return (
        <nav className="flex items-center justify-between px-6 sticky top-0 bg-gray-400 opacity-100 bg-opacity-100">
            <Link href={"/"}>
                <span className="sr-only">Booking cpp</span>
                <Image className="w-auto" src='/Logo (1).png' alt="logo" width={100} height={100} priority={true}/>
            </Link>
            <div className="flex-grow-1">
                <Searcher/>
            </div>
            <div className="flex justify-between">
                <div className="px-2">
                    <Link href={"/rentOut"}>
                        <div className="rounded-full py-2 px-2 bg-gray-400 hover:bg-gray-500">Сдать жильё</div>
                    </Link>
                </div>
                <div
                    className="bg-white rounded-full py-2 px-2 drop-shadow-none
                         hover:drop-shadow">
                    <button
                        //todo: решить проблему с вёрсткой: при малой ширине окна картикни вылазят за блок с кнопками
                        className="flex justify-between">
                        <Image src='/hamburger.svg' alt="menu" width={30} height={30}/>
                        <Image src='/user.svg' alt="user" width={30} height={30}/>
                    </button>
                </div>
            </div>
        </nav>
    )
}

export default Navbar;