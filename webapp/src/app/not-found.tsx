import React from "react";
import Link from "next/link";
import Image from "next/image";

export default function NotFound() {
    return(
        <div className="flex items-center justify-center h-screen flex-wrap">
            <div>
                <div className="flex ">
                    <Image src="/oops.svg" alt="oops img" width={60} height={60}/>
                    <div className="flex items-center px-2">
                        <h1>Упс страница не найдена</h1>
                    </div>
                </div>
                <div className="pl-16">
                    <p className="text-blue-300 hover:text-blue-500">
                        <Link href={'/'}>Вернуться на главную</Link>
                    </p>
                </div>
            </div>
        </div>
    )
}